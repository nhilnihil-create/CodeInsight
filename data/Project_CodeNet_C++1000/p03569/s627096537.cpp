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
    bool isok = true;
    int ans = 0;
    for(int i = 0, j = s.size()-1; i<j;){
        if (s[i] == s[j]) i++, j--;
        else if (s[i] == 'x') i++,ans++;
        else if (s[j] == 'x') j--,ans++;
        else isok = false;
        if (!isok) break;
    }
    if(isok) cout << ans << endl;
    else cout << -1 << endl;
}

