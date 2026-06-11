#include<bits/stdc++.h>
using namespace std;


int main(){
  int a,b,k;
  //cout << '1' << endl;
  cin >> a >> b >> k;
  map<int,int> mp;
  for(int i=a;i<a+k;++i){
    mp[i]++;
    //cout << i << endl;
  }
  for(int i=b;i>b-k;--i){
    mp[i]++;
  }
  for(auto p : mp){
    if(p.first>=a && p.first<=b){
      cout << p.first << endl;
    }
  }
  return 0;
}
