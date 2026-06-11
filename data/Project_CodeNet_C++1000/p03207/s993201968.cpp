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
  vector<long long int> hoge(n);
  for(long long int i=0; i<n; i++){
    cin>>hoge.at(i);
  }
  sort(hoge.begin(),hoge.end());
  hoge.at(n-1)=hoge.at(n-1)/2;
  long long int ans=0;
  for(long long int i=0; i<n; i++){
    ans+=hoge.at(i);
  }
  cout<<ans<<endl;
}