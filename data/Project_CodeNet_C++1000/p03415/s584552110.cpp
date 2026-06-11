#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll fac(ll n){if(n<=1)return 1; else return n*fac(n-1);}
int main()
{
    string ans;
    vector<string>s(3);
    for(int i=0;i<3;i++)cin >> s[i];
    for(int i=0;i<3;i++)ans+=s[i][i];
    cout << ans << endl;
}
