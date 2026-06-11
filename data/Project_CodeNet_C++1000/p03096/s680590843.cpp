#include "bits/stdc++.h"
using namespace std;

#define int long long
#define mod 1000000007ll

int arr[200005],n;
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
		cin>>n;
    int ways=1,c[n],t;
    for(int x=0;x<n;x++){
      cin>>c[x];
      if(x>0 && c[x]==c[x-1])continue;
      t=arr[c[x]];
      arr[c[x]]+=ways;
      arr[c[x]]%=mod;
      if(x==0 || c[x]!=c[x-1]){
        ways+=t;
        ways%=mod;
      }
    }
    cout<<ways;
    return 0;
}
