#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;
const ll LINF=1e18;

int main(){
    int n,k,q;
    cin>>n>>k>>q;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    int ans=2e9;
    for(int i=0;i<n;i++){
        int mn=b[i];
        int ok=n,ng=i-1;
        while(ok-ng>1){
            int mid=(ok+ng)/2;
            int mx=b[mid];
            int lensum=0;
            for(int j=0;j<n;j++){
                int len=0,cnt=0;
                while(j<n&&mn<=a[j]){
                    if(a[j]<=mx)cnt++;
                    j++;
                    len++;
                }
                lensum+=min(max(0,len+1-k),cnt);
            }
            if(lensum>=q)ok=mid;
            else ng=mid;
        }
        if(ok!=n){
            ans=min(ans,b[ok]-mn);
        }
    }
    cout<<ans<<endl;
}
