#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  bool le,ri,c;
  string s;
  cout << 0<<endl;
  cin>>s;
  if(s=="Vacant")return 0;
  map<string,bool> mp;
  mp["Female"]=0;
  mp["Male"]=1;
  ri=mp[s];
  cout<<n-1<<endl;
  cin>>s;
  if(s=="Vacant")return 0;
  le=mp[s];
  int mi=0,ma=n-1,mid=(ma+mi)/2;
  while(1){
    cout<<mid<<endl;
    cin>>s;
    if(s=="Vacant")break;
    c=mp[s];
    if(((ma-mid)%2)^(le==c)){
        le=c;
        ma=mid;
    }else{
        ri=c;
        mi=mid;
    }
    mid=(ma+mi)/2;
  }
  return 0;
}
