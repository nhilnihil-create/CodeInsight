#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  bool le,ri,c;
  string s;
  cout << 0<<endl;
  cout << flush;
  cin>>s;
  if(s=="Vacant")return 0;
  map<string,bool> mp;
  mp["Female"]=0;
  mp["Male"]=1;
  ri=mp[s];
  cout<<n-1<<endl;
  cout << flush;
  cin>>s;
  if(s=="Vacant")return 0;
  le=mp[s];
  int mi=0,ma=n-1,mid=(ma+mi)/2;
  while(1){
    cout<<mid<<endl;
    cout << flush;
    cin>>s;
    if(s=="Vacant")break;
    c=mp[s];
    if((ma-mid)%2){
        if(le==c){
            ri=c;
            mi=mid;
        }
    }else{
        if(le!=c){
            ri=c;
            mi=mid;
        }
    }
    if((mid-mi)%2){
        if(ri==c){
            le=c;
            ma=mid;
        }
    }else{
        if(ri!=c){
            le=c;
            ma=mid;
        }
    }
    mid=(ma+mi)/2;
  }
  return 0;
}
