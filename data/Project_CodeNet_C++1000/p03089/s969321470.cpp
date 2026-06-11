#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int,bool>>a(n,make_pair(0,true));
  vector<int>num(n,0);
  for(int i=0;i<n;i++){
    cin >> a.at(i).first;
    num.at(a.at(i).first-1)++;
  }
  bool ok=true;
  for(int i=0;i<n;i++)
    if(a.at(i).first>i+1)
      ok=false;
  //cout << (ok?"1$":"-1$") << endl;
  if(ok){
    int i=1,l=0,k=0;
    while(i<=n){
      if(a.at(n-i).second){
        if(a.at(n-i).first==1||(l-a.at(n-i).first>=-1&&l+1>=k+a.at(n-i).first)){
          cout << a.at(n-i).first << /*"&" << n-i <<*/ endl;
          a.at(n-i).second=false;
          i=0,k=0;
          l++;
        }
      }else{
        k++;
      }
      i++;
      bool br=true;
      for(int j=0;j<n;j++)
        br&=!a.at(j).second;
      if(br) break;
    }
  }else{
    cout << -1 << endl;
  }
  return 0;
}

