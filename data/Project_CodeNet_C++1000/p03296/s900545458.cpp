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
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}
    int ans = 0;
    int len = 0;
    int bef = a[0];
    rep1(i, n-1){
        if (a[i] == a[i-1]){
            len++;
        } else {
            ans += (len+1)/2;
            len = 0;
        }
        bef = a[i];
    }
    ans += (len+1)/2;
    cout << ans << endl;
}

