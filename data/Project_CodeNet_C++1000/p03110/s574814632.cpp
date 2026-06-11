#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n; cin >> n;
    double ans = 0;
    rep(i,n){
        double d; string s;
        cin >> d >> s;
        if(s == "JPY") ans += d;
        else ans += d * 380000.0;
    }
    cout << fixed << setprecision(10) << ans << endl;
}