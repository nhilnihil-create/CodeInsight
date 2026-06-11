#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin >> n;
  vector<string> s(n);
  cout << 0 << endl;
  cin >> s[0];
  if(s[0]=="Vacant"){
    return 0;
  }
  int l=0,r=n;
  while(1){
    int mid=(l+r)/2;
    cout << mid << endl;
    cin >> s[mid];
    if(s[mid]=="Vacant"){
      return 0;
    }
    if((s[l]==s[mid])^((mid-l)%2==0)){
      r=mid;
    }
    else{
      l=mid;
    }
  }
}