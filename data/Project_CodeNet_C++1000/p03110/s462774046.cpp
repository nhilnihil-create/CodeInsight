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
  long double ans=0;
  for(long long int i=0; i<n; i++){
    long double x;
    string s;
    cin>>x>>s;
    if(s=="BTC"){
      ans+=x*380000.0;
    }else{
      ans+=x;
    }
  }
  cout<<fixed<<setprecision(10)<<ans<<endl;
}