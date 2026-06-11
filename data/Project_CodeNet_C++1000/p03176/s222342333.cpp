#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,h[mxN],v[mxN],bit[mxN];
void upd(int pos,int val){
    while(pos<mxN){
        bit[pos]=max(bit[pos],val);
        pos+=(pos&-pos);
    }
}
int query(int pos){
    int ans=0;
    while(pos>0){
        ans=max(ans,bit[pos]);
        pos-=(pos&-pos);
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];h[i]++;
    }
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++){
        int temp=query(h[i]-1)+v[i];
        upd(h[i],temp);        
    }
    cout<<query(mxN-1);
}