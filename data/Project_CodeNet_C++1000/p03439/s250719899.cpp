#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep1(i,n) for(ll i=1;i<=n;++i)
int main(){
  int n;cin>>n;
  string str="null";
  int s=0;
  string sl,sr;
  int t=n-1;
  cout<<0<<endl;
  cin>>sl;
  cout<<n-1<<endl;
  cin>>sr;
  if(sl=="Vacant"||sr=="Vacant")goto FINE;
  while(str!="Vacant"){
    int mid=(s+t)/4;
    mid*=2;
    if(mid==s)mid++;
    cout<<mid<<endl;
    cin>>str;
    if(str==sl){
      s=mid;
    }
    else{
      t=mid;
    }
  }
  FINE:
  return 0;
}