#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
using namespace std;
typedef long long unsigned int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

long long beki(int a, long long b)
{
    if(b == 0){
        return 1;
    }
    long long ans = beki(a, b / 2);
    ans = ans * ans;
    if(b % 2 == 1){
        ans *= a;
    }
    return ans;
}

long long S(long long n)
{
    if(n < 10){
        return n;
    }
    return (n % 10) + S(n / 10);
}

int main() {
    //cout.precision(10);
    stack<long long> ans;
    double checker = 10000000000000000000000.0;
    for(long long l = 10; l >= 0; l--){
        for(long long k = 100000; k >= 10001; k--){
            long long check = beki(10, l) * k - 1;
            if((double)check / (double)S(check) <= checker){
                ans.push(check);
                checker = (double)check / (double)S(check);
            }
        }
    }
    for(long long k = 9999; k >= 1; k--){
            if((double)k / (double)S(k) <= checker){
                ans.push(k);
                checker = (double)k / (double)S(k);
            }
    }
    long long q;
    cin >> q;
    for(int i = 1; i <= q; i++){
        long long out = ans.top();
        ans.pop();
        cout << out << endl;
        if(ans.empty()){
            break;
        }
    }
    return 0;
}
