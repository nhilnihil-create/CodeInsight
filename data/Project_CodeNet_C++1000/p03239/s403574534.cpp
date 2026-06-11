#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
  long long int n,t;
  cin>>n>>t;
  vector<pair<long long int,long long int>> hoge(n);
  for(long long int i=0; i<n; i++){
    cin>>hoge.at(i).first>>hoge.at(i).second;
  }
  long long int ans=9999999999;
  bool ok=false;
  for(long long int i=0; i<n; i++){
    if(hoge.at(i).second<=t){
      ok=true;
      ans=min(ans,hoge.at(i).first);
    }
  }
  if(ok){
    cout<<ans<<endl;
  }else{
    cout<<"TLE"<<endl;
  }
}