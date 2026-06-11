#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  int l=0,r=n-1;
  cout<<l<<endl<<flush;
  string s; cin>>s;
  if(s=="Vacant") return 0;
  cout<<r<<endl<<flush;
  string t; cin>>t;
  if(t=="Vacant") return 0;
  while(true){
    int mid=(l+r)/2;
    cout<<mid<<endl<<flush;
    string x; cin>>x;
    if(x=="Vacant") return 0;
    if(mid%2==0 && s==x) l=mid;
    else if(mid%2==1 && s!=x) l=mid;
    else r=mid;
  }
}