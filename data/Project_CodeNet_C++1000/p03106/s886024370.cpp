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
  long long int a,b;
  cin>>a>>b;
  long long int k;
  cin>>k;
  long long int count=0;
  long long int now=1;
  vector<long long int> hoge;
  for(long long int i=1; i<=100; i++){
    if(a%i==0&&b%i==0){
      hoge.push_back(i);
    }
  }
  cout<<hoge.at(hoge.size()-k)<<endl;
}