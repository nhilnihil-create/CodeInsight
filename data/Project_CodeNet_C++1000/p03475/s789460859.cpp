#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n-1), s(n-1), f(n-1);
    rep(i, n-1)cin >> c[i] >> s[i] >> f[i];
    for(int i = 0; i < n; i++){
        int now = 0;
        for(int j = i; j < n-1; j++){
            if(now < s[j])now = s[j];
            else if(now % f[j] == 0);
            else now += f[j] - now % f[j];
            now += c[j];
        }
        cout << now << endl;
    }
}
