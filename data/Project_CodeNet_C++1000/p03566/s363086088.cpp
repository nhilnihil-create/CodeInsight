#ifdef LOCAL
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <limits>
#else
#include <bits/stdc++.h>
#endif
using namespace std ;
#define all(a) (a).begin(), (a).end()
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
#define RREP(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define ios() cin.tie(0), ios::sync_with_stdio(false)
typedef long long ll;
typedef unsigned long long ull;
ll const MOD = 1e9+7;
ll const INF = 1e18;

int main(){
    ios();
    int n;
    cin >> n;

    int total = 0;
    vector<int> t(n), v(n);
    REP(i, n){
        int a;
        cin >> a;
        t[i] = t[max(0, i-1)] + a;
    }
    for(int& i : v){
        cin >> i;
    }
    v.push_back(0);

    double speed = 0.0, ans = 0.0;
    int area = 0;

    for(double i = 0.0; i < t.back(); i += 0.5){
        double speed2 = speed;
        bool down = false;
        if(i == t[area]){
            area++;
        }
        for(int j = area; j < n; j++){
            if(speed - v[j+1] >= t[j] - i){
                down = true;
                break;
            }
        }
        if(down){
            speed2 -= 0.5;
        }else if(speed < v[area]){
            speed2 += 0.5;
        }
        ans += (speed + speed2) * 0.25;
        speed = speed2;
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
