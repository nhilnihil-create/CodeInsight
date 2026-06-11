#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
int ans[100005];
int x[100005];
int main(void){
    int n;
    int q;
    string s;
    cin>>n>>q>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]=='A'&&s[i+1]=='C'){
            ans[i+1]++;
            x[i]=1;
        }
        if(i>0){
            ans[i+1]=ans[i+1]+ans[i];
        }
        //cout<<i<<" "<<ans[i+1]<<endl;
    }
    ans[n]=ans[n-1];
    while(q--){
        int l,r; cin>>l>>r;
        cout<<ans[r]-ans[l-1]-x[r-1]<<endl;
    }
    
}
