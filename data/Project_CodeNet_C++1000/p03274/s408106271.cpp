#include<bits/stdc++.h>
using namespace std;

int x[100001];

int main(){
    int n,k; cin >> n >> k;
    for(int i=0;i<n;i++) cin >> x[i];

    int ans=1e9;
    int zero=n;
    bool zeroaru=false;
    for(int i=0;i<n;i++){
        if(x[i]>0){
            zero=i; break;
        }else if(x[i]==0){
            zero=i; zeroaru=true; break;
        }
    }
    if(zero+int(zeroaru)>=k){
        ans=min(ans,abs(x[zero+int(zeroaru)-k]));
    }
    if(n-zero>=k){
        ans=min(ans,abs(x[zero+k-1]));
    }
    for(int i=0;i<=n-k;i++){
        ans=min(abs(x[i])+abs(x[i+k-1])*2,ans);
        ans=min(abs(x[i])*2+abs(x[i+k-1]),ans);
    }
    cout << ans << endl;
}