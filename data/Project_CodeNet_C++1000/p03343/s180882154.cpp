#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    int n,k,q;
    cin>>n>>k>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=2e9;
    for(int i=0;i<n;i++){
        vector<int> vv;
        int mn=a[i];
        for(int j=0;j<n;j++){
            vector<int> v;
            while(j<n&&mn<=a[j]){
                v.push_back(a[j]);
                j++;
            }
            if(v.size()>=k){
                sort(v.begin(),v.end());
                for(int l=0;l<(int)v.size()+1-k;l++){
                    vv.push_back(v[l]);
                }
            }
        }
        if(vv.size()>=q){
            sort(vv.begin(),vv.end());
            ans=min(ans,vv[q-1]-mn);
        }
    }
    cout<<ans<<endl;
}
