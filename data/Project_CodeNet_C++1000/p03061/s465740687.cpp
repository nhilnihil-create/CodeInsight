#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stdlib.h>
#include <tuple>
#include <iomanip>
#include <iterator>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <bit>
#include <bitset>
#include <cstdint>
using namespace std;
const double PI = 3.14159265358979323846;
const long long int MOD = 1000000000 + 7;

struct UnionFind {
    vector<int> parent;

    UnionFind(int N) : parent(N) {
        for (int i = 0; i < N; i++) {
            parent[i] = -1;
        }
    }

    int root(int i) {
        if (parent[i] < 0) {
            return i;
        }
        return (parent[i] = root(parent[i]));
    }

    bool unite(int from, int to) {
        int rx = root(from);
        int ry = root(to);
        if (rx != ry) {
            parent[ry] += parent[rx];
            parent[rx] = ry;

            return true;
        }
        else {
            return false;
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int treeSize(int x) {


        return -parent[root(x)];
    }
};

long long int modpow(long long int base, long long int pow, long long int mod) {
    if (pow == 1) {
        return base;
    }
    else if (pow == 0) {
        return 1;
    }

    if (pow % 2 == 0) {
        auto temp = modpow(base, pow / 2, mod);
        return (temp * temp) % mod;
    }
    else {
        return (base * modpow(base, pow - 1, mod)) % mod;
    }
}

long long int moddiv(long long int X, long long int Y, long long int mod) {
    auto fermatDiv = modpow(Y, mod - 2, mod);

    return (X * fermatDiv) % mod;
}

long long modCombination(long long left, long long right, long long int mod) {
    long long answer = 1;
    if (left > right) {
        for (long long i = 0; i < right; i++) {
            answer = (answer * (left - i)) % mod;
            answer = moddiv(answer, (i + 1), mod);
        }
    }
    return answer;
}

bool IsPrime(long long N) {
    if (N == 1) {
        return false;
    }
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            return false;
        }
    }


    return true;
}


vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
            
        }

        // その結果を push
        res.push_back({ a, ex });
    }

    // 最後に残った数について
    if (N != 1) res.push_back({ N, 1 });
    return res;
}

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i) res.push_back(N / i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

long long gcd(long long a, long long b) {
    if (b > a) {
        long long temp = b;
        b = a;
        a = temp;
    }
    //cout << "a:" << a << "b:" << b << endl;
    long long c = a % b;
    if (c == 0) {
        return b;
    }
    else {
        return gcd(b, c);
    }
}


int N;
vector<vector<int>> graph;
void Find1toN(stack<int>& v, int pre, int from) {
    
    int size = graph[pre].size();
    for (int i = 0; i < size; i++) {
        if (graph[pre][i] != from) {
            v.push(graph[pre][i]);
            if (graph[pre][i] == N) {
                return;
            }

            Find1toN(v, graph[pre][i], pre);
            if (v.top() != N) {
                v.pop();
            }
            else {
                return;
            }
        }
    }
}

int GetChildrenCount(int node, int preNode, int count, int except) {
    int currentCount = count + 1;
    int size = graph[node].size();
    for (int i = 0; i < size; i++) {
        if (graph[node][i] != preNode && graph[node][i] != except) {
            currentCount = GetChildrenCount(graph[node][i], node, currentCount, -1);
        }
    }

    return currentCount;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A[i] = a;
    }

    sort(A.begin(), A.end());

    int secondMinimum = A[1];
    auto secondDiv = enum_divisors(secondMinimum);
    sort(secondDiv.begin(), secondDiv.end(), greater<long long>());

    int secondGCD = 0;
    for (auto d : secondDiv) {
        int penaltyCount = 0;
        for (auto a : A) {
            if (a % d != 0) {
                penaltyCount++;
            }
            if (penaltyCount >= 2) {
                break;
            }
        }
        if (penaltyCount <= 1) {
            secondGCD = d;
            break;
        }
    }

    int firstMinimum = A[0];
    if (secondGCD >= firstMinimum) {
        cout << secondGCD << endl;
        return 0;
    }

    auto firstDiv = enum_divisors(firstMinimum);
    sort(firstDiv.begin(), firstDiv.end(), greater<long long>());

    int firstGCD = 0;
    for (auto d : firstDiv) {
        int penaltyCount = 0;
        for (auto a : A) {
            if (a % d != 0) {
                penaltyCount++;
            }
            if (penaltyCount >= 2) {
                break;
            }
        }
        if (penaltyCount <= 1) {
            firstGCD = d;
            break;
        }
    }

    if (firstGCD >= secondGCD) {
        cout << firstGCD << endl;
    }
    else {
        cout << secondGCD << endl;
    }
    return 0;
}