#include <bits/stdc++.h>
using namespace std;


int main() {

  int n;
  cin>>n;

  map<string,int> w_map;
  bool flg=true;
  string w_old="dummy";
  for(int i=0;i<n;i++){
    string w;
    cin>>w;

    if(w_map.count(w))
      flg=false;
    else
      w_map[w]=1;

    if(i>0){
      if(w.front()!=w_old.back())
        flg=false;
    }
    w_old=w;
  }

  if(flg)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

  return 0;
}


