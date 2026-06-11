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
  string s,t;
  cin>>s>>t;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end());
  long long int sstr=1;
  long long int tstr=1;
  vector<long long int> sset,tset;
  for(long long int i=1; i<s.size(); i++){
    if(s[i]==s[i-1]){
      sstr++;
    }else{
      sset.push_back(sstr);
      sstr=1;
    }

    if(t[i]==t[i-1]){
      tstr++;
    }else{
      tset.push_back(tstr);
      tstr=1;
    }
  }
  sset.push_back(sstr);
  tset.push_back(tstr);
  sort(sset.begin(),sset.end());
  sort(tset.begin(),tset.end());
  if(sset==tset){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}