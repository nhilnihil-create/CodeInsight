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
  vector<int> c;
  vector<int> s;
  vector<int> f;
  long long int n;
void saiki(int now,int t){
  if(now==n-1){
    cout<<t<<endl;
    return;
  }
  if(t<s.at(now)){
    saiki(now+1,s.at(now)+c.at(now));
  }else{
    while(true){
      if(t%f.at(now)==0) break;
      t++;
    }
    saiki(now+1,t+c.at(now));
  }
}
int main(void){
  cin>>n;
  c.resize(n-1);
  s.resize(n-1);
  f.resize(n-1);
  for (int i = 0; i < n-1; i++)
  {
    cin>>c.at(i)>>s.at(i)>>f.at(i);
  }
  
  for(int i=0; i<n; i++){
    saiki(i,0);
  }
}