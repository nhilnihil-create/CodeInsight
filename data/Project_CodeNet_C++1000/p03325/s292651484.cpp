#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i, o) for (int i = 0; i < (o); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
#define NUM 1e5

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
    int n;
    cin >> n;

    ull a[n];
    rep(i, n) {
        cin >> a[i];
    }

    ull count = 0;
    rep(i, n) {
        while (a[i]%2 == 0)
        {
            count++;
            a[i] /= 2;
        }
        // cout << count << endl;
    }
    
    cout << count << endl;
    return 0;
}