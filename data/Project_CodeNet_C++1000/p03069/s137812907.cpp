#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

int main(){
int n;string s;
cin>>n>>s;
int sum[n+1];
sum[0]=0;
for(int i=1;i<=n;i++){
    sum[i]=sum[i-1]+(s[i-1]=='.');
}
int ans=n;
for(int i=0;i<=n;i++){
    int a=sum[n]+i-2*sum[i];
    ans=min(a,ans);
}
cout<<ans;

}