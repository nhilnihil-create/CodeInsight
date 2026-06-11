#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
typedef pair<int,int>pii;
const int mxN=2e5,M=1e9+7;
int m,k;
// LONG LONG CASE
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    cin>>m>>k;
    int tot=1<<m;
    if(k>=tot)cout<<-1;
    else if(m==1){
        if(k==0)cout<<"0 0 1 1";
        else cout<<-1;
    }
    else{
        vector<int>v;
        for(int i=0;i<tot;i++){
            if(i!=k)v.pb(i);
        }
        v.pb(k);
        for(int i=tot-1;i>=0;i--){
            if(i!=k)v.pb(i);
        }
        v.pb(k);
        for(int u:v){
            cout<<u<<" ";
        }
    }
    
}