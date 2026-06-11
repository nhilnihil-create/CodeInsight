#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll fac(ll n){if(n<=1)return 1; else return n*fac(n-1);}
int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    for(int i=n;i<=m;i++)
    {
        string s=to_string(i);
        int f = 1;
        for(int j=0,k=s.size()-1;j<k;j++,k--)
            if(s[j]!=s[k])f=0;
        if(f)ans++;
    } cout << ans << endl;
}
