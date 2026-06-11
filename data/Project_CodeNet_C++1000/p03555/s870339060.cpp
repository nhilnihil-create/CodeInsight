#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=1e5+9;
int main()
{
    FASTINOUT;
    string s,t;
    cin>>s>>t;
    if (s[0]==t[2]&&s[1]==t[1]&&s[2]==t[0])
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
