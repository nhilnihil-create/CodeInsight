#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    if(n<a+b-1||a*b<n){
        cout<<-1<<endl;
        return 0;
    }
    vector<ll> ans;
    ll remove=a*b-n;
    for(ll i=0;i<b;i++){
        for(ll j=0;j<a;j++){
            if(i>0&&j==1&&remove>0){
                ll t=min(a-1,remove);
                remove-=t;
                j+=t-1;
            }
            else ans.push_back(a*b-i*a-a+j+1);
        }
    }
    vector<pair<ll,int>> v;
    for(int i=0;i<ans.size();i++){
        v.push_back({ans[i],i});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        ans[v[i].second]=i+1;
    }
    for(int v:ans){
        cout<<v<<" ";
    }
    cout<<endl;
}