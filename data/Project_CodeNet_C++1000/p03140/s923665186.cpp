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
    string a, b, c;
    cin >> a >> b >> c;

    int ans_total = 0;
    rep(i, n){
        int ans = 0;
        if (a[i] != b[i] && b[i] != c[i] && a[i] != c[i]){
            ans = 2;
        } else if ( a[i] == b[i] && b[i] == c[i]) {
            ans = 0;
        } else {
            ans = 1;
        }
        ans_total += ans;
    }
    cout << ans_total << endl;
 
}

