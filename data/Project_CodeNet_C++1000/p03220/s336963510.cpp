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
  long double n,t,a;
  cin>>n>>t>>a;
  vector<long long int> h(n);
  for(long long int i=0; i<n; i++){
    cin>>h.at(i);
  }
  long long int ans;
  long double now=99999999999;
  for(long long int i=0; i<n; i++){
    if(abs(a-(t-h.at(i)*0.006))<now){
      ans=i;
      now=abs(a-(t-h.at(i)*0.006));
    }
  }
  cout<<ans+1<<endl;
}