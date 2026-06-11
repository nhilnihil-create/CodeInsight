#include<bits/stdc++.h>
#define ll int
using namespace std;
const int N=2e5+4;
ll ans[N];
int main(){
       ll n;
       cin>>n;
       ll a[n];
       for(int i=0;i<n;i++) cin>>a[i];
       ll fuck=1;
       for(int i=0;i<n;i++){
              int cur=a[i];
              ans[cur]=max(ans[cur],ans[cur-1]+1);
              fuck=max(fuck,ans[cur]);
       }
       cout<<n-fuck;
       
       return 0;
}