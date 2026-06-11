#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>

#define ll long long
#define REP(i,n) for(int i = 0; i < (n); ++i)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){ return (a % b)? gcd(b, a%b) : b; }
template<typename T> T lcm(T a, T b){ return a * b / gcd(a, b); }

int main(void){
    int n, m;
    cin >> n >> m;
    pair<ll, ll> p[n];
    REP(i,n) cin >> p[i].first >> p[i].second;

    sort(p, p+n, [](pair<int, int> x, pair<int, int> y){return x.first < y.first;});
    ll ans = 0;
    int i = 0;
    while(1){
        if(m-p[i].second > 0){
            ans += p[i].first * p[i].second;
            m -= p[i].second;
        } else{
            ans += p[i].first * m;
            break;
        }
        i++;
    }
    cout << ans << endl;
}