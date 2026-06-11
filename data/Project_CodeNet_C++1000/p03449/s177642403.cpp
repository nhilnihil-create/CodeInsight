#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

#define rep(i, o) for (int i = 0; i < (o);i++)
#define rep_s(i, o) for (int i = 1; i < (o);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)
#define NUM 1e5

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
    int n;
    cin >> n;

    int candies[2][n];
    rep(i, 2) {
        rep(j, n) {
            cin >> candies[i][j];
        }
    }

    int s[n+1][2];
    s[0][0] = candies[0][0]; s[0][1] = 0;
    rep_s(i, n) {
        s[i][0] = s[i-1][0] + candies[0][i]; // right
        s[i][1] = max(s[i-1][1] + candies[1][i-1], s[i-1][0] + candies[1][i-1]);   // down
        // cout << s[i][0] << " " << s[i][1] << endl;
    }
    s[n-1][1] = max(s[n-1][0] + candies[1][n-1], s[n-1][1] + candies[1][n-1]);
    cout << s[n-1][1] << endl;
    return 0;
}