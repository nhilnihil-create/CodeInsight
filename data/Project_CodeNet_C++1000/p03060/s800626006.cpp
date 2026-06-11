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
  long long int n;
  cin>>n;
  vector<long long int> v(n);
  for(long long int i=0; i<n; i++){
    cin>>v.at(i);
  }
  vector<long long int> c(n);
  for(long long int i=0; i<n; i++){
    cin>>c.at(i);
  }
  long long int ans=0;
  for(long long int i=0; i<n; i++){
    if(v.at(i)>c.at(i)){
      ans+=v.at(i)-c.at(i);
    }
  }
  cout<<ans<<endl;
}