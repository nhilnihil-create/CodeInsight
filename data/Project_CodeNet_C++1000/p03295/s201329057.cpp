#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> a(m);
    rep(i, m){ cin >> a[i].first >> a[i].second;}

    sort(a.begin(), a.end());

    int r = 0;
    int ans = 0;
    rep(i, m){
        if (r <= a[i].first){
            r = a[i].second;
            ans++;
        } else if (a[i].second < r){
            r = a[i].second;
        }
    }

    cout << ans << endl;

}

