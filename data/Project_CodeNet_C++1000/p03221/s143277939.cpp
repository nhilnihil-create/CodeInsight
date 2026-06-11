#include<bits/stdc++.h>
#include<tuple>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;vector<ll>v[100005];
    cin>>n>>m;map<ll,ll>pos;
    ll p[m+1],y[m+1];
    for(int i=1;i<=m;i++){
        cin>>p[i]>>y[i];
        v[p[i]].push_back(y[i]);
    }
    for(int i=1;i<=n;i++){
        sort(v[i].begin(),v[i].end());
        for(int j=0;j<v[i].size();j++){
            pos[v[i][j]]=j+1;
        }
    }
    for(int i=1;i<=m;i++){
        if(p[i]>=0&&p[i]<=9){cout<<"00000"<<p[i];}
        else if(p[i]>=10&&p[i]<=99){cout<<"0000"<<p[i];}
        else if(p[i]>=100&&p[i]<=999){cout<<"000"<<p[i];}
        else if(p[i]>=1000&&p[i]<=9999){cout<<"00"<<p[i];}
        else if(p[i]>=10000&&p[i]<=99999){cout<<"0"<<p[i];}
        else if(p[i]>=100000&&p[i]<=999999){cout<<p[i];}
        if(pos[y[i]]>=0&&pos[y[i]]<=9){cout<<"00000"<<pos[y[i]];}
        else if(pos[y[i]]>=10&&pos[y[i]]<=99){cout<<"0000"<<pos[y[i]];}
        else if(pos[y[i]]>=100&&pos[y[i]]<=999){cout<<"000"<<pos[y[i]];}
        else if(pos[y[i]]>=1000&&pos[y[i]]<=9999){cout<<"00"<<pos[y[i]];}
        else if(pos[y[i]]>=10000&&pos[y[i]]<=99999){cout<<"0"<<pos[y[i]];}
        else if(pos[y[i]]>=100000&&pos[y[i]]<=999999){cout<<pos[y[i]];}
        cout<<endl;
    }
}
