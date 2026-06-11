#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,c=0,ok=1;
    cin>>n;map<string ,ll>m;char a;
    while(n--){++c;
        string s;
        cin>>s;
        if(m[s]){
            ok=0;
        }
        if(c>=2&&s[0]!=a){
            ok=0;
        }
        m[s]=1;a=s[s.size()-1];
    }
    if(ok)cout<<"Yes\n";
    else cout<<"No\n";
}
