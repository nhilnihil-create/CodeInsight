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
  long long int n,m;
  cin>>n>>m;
  map<long long int,long long int> hoge;
  for(long long int i=0; i<n; i++){
    long long int k;
    cin>>k;
    for(long long int j=0; j<k; j++){
      long long int x;
      cin>>x;
      hoge[x]++;
    }
  }
  long long int ans=0;
  for(long long int i=1; i<=m; i++){
    if(hoge[i]==n){
      ans++;
    }
  }
  cout<<ans<<endl;
}