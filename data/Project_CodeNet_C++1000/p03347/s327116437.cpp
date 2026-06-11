#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
#define int long long
int a[200100],b[200100],n,m,ans;
signed main(){
    int i,j,k;
    scanf("%lld",&n);
    for(i=1;i<=n;i++){
      scanf("%lld",&a[i]);
      b[i]=i-a[i];
      if(a[i]-a[i-1]>1||a[i]>=i){
        puts("-1");
        return 0;
      }
    }
    for(i=n;i>0;i--){
      if(i!=n&&b[i]==b[i+1])continue;
      ans+=a[i];
    }
    cout<<ans<<"\n";
    return 0;
}