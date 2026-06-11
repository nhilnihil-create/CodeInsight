#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s>>t;
    vector<ll>ser(26,-1),ter(26,-1);
    for(int i=0;i<s.size();i++){
        ll x=s[i]-'a';
        ll y=t[i]-'a';
        if(ser[x]!=-1&&ser[x]!=y){
            cout<<"No\n";return 0;
        }
        if(ter[y]!=-1&&ter[y]!=x){
            cout<<"No\n";return 0;
        }
        ser[x]=y;
        ter[y]=x;
    }
    cout<<"Yes\n";
}
