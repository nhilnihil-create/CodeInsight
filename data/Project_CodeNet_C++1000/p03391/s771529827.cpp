#include <bits/stdc++.h>
using namespace std;
long long INF=99999999999;

long long n,k[200005],l[200005],sum,mon=INF;
int main(){
  cin>>n;
  for(int i=0;i<n;++i){
    cin>>k[i]>>l[i];
    sum+=k[i];
    if(k[i]>l[i]){mon=min(mon,l[i]);}
  }
  if(mon==INF){
    cout<<0<<endl;
    return 0;
  }
  cout<<sum-mon<<endl;
}
