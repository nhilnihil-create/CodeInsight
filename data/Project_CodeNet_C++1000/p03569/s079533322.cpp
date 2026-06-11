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
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    s += "0";
    t += "0";
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == 'x') continue;
    //     t += s[i];
    // }
    
    // bool ans = true;
    // for (int i = 0; i < t.size()/2; i++)
    // {
    //     if (t[i] != t[t.size()-1-i]) ans = false;
    // }

    int n = s.size()-1;
    int itr_l = -1;
    int itr_r = -1;
    int ans = 0;
    while(1){
        int xl = 0;
        int xr = 0;
        itr_l++;
        itr_r++;
        while(s[itr_l] == 'x' && itr_l < n){
            itr_l++;
            xl++;
        }
        while(t[itr_r] == 'x' && itr_r < n){
            itr_r++;
            xr++;
        }
        if (s[itr_l] != t[itr_r]){
            ans = -1;
            break;
        } else {
            ans += abs(xl-xr);
        }
        if (itr_l == n) break;
        if (itr_r == n) break;
    }

    if (ans == -1) cout << ans << endl;
    else cout << ans/2 << endl;
    return 0;
}

