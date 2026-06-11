#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l1[51][51];
ll dir[8][2]={{1,0},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1},{1,-1},{1,1}};
map<ll,ll>di;


int main()
{
    string s,t;//cout<<min(s,t)<<endl;
    cin>>s;
    cin>>t;
    ll n,m;
    n=s.size();
    m=t.size();
    if(m>n){
        cout<<"UNRESTORABLE";return 0;
    }
    string ans="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for(int i=0;i<=n-m;i++){
        string s2=s;bool ok=true;
        for(int j=0;j<m;j++){
            if(s[i+j]!='?'&&s[i+j]!=t[j])ok=false;
            s2[i+j]=t[j];
        }
        if(ok){//cout<<1<<endl;
            replace(s2.begin(),s2.end(),'?','a');
            ans=min(ans,s2);
        }
    }
    if(ans=="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz")cout<<"UNRESTORABLE";
    else cout<<ans;
}
