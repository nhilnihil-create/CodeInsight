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
  long long int all=0;
  for(long long int i=0; i<n; i++){
    cin>>hoge.at(i);
    all+=hoge.at(i);
  }
  sort(hoge.begin(),hoge.end());
  if(all-hoge.at(n-1)>hoge.at(n-1)){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}