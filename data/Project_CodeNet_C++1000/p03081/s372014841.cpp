#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <functional>
#include <climits>

using namespace std;
int n, q;
vector<int> go; //ゴーレムiの位置: go[i]
vector<char> t, d;
string s;

// 最後の位置
int posi(int ind) {
    vector<int> l_go = vector<int>(go);
    for(size_t i = 0; i < q; i++)
    {
        if(l_go[ind] < 0) {
            return -1;
        } else if(l_go[ind] > n-1) {
            return n;
        }
        if(s[l_go[ind]] == t[i]) {
            if(d[i] == 'R') l_go[ind] += 1;
            else l_go[ind] -= 1;
        }
    }
    return l_go[ind];
}

// 0以上の境界 first <= index < last
int binsearch_zero(int first, int last) {
    while (first < last) { //lastは次を指すので重ならない
        int mid = (first+last)/2;
        int p = posi(mid);
        if(p == 0) { //一致は決定するのでさっさと除いた方がわかりやすい。
            return mid;
        } else if (p > 0) {
            // lastは探索範囲の1つ外。
            last = mid;
        } else {
            first = mid + 1; //範囲を1つ進められるのはpをはじめにのぞいているからand firstが含まれるから
        }
    }
    return first;
}

// n-1以下になる最大のもの
int binsearch_n(int first, int last) {
    if(first == last) return first-1;
    int mid = (first+last)/2;
    int p = posi(mid);
    if(p == n-1) {
        return mid;
    } else if(p > n-1) {
        return binsearch_n(first, mid);
    } else {
        return binsearch_n(mid + 1, last);
    }
}

int main() {
    int sum = 0;
    cin >> n >> q >> s;
    vector<int> l_go(n);
    vector<char> l_t(q), l_d(q);
    for(size_t i = 0; i < n; i++)
    {
        l_go[i] = i;
    }
    go = l_go;
    for(size_t i = 0; i < q; i++)
    {
        cin >> l_t[i] >> l_d[i];
    }
    t = l_t;
    d = l_d;
    int b_z = binsearch_zero(0, n);
    int b_n = binsearch_n(0, n);
    cout << b_n - b_z + 1 << endl;
}
