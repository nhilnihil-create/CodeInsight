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
  long long int s;
  cin>>s;
  map<long long int,long long int> hoge;
  hoge[s]++;
  long long int count=2;
  while(true){
    if(s%2==0){
      s/=2;
    }else{
      s=s*3+1;
    }
    if(hoge.count(s)){
      break;
    }else{
      count++;
      hoge[s]++;
    }
  }
  cout<<count<<endl;
}