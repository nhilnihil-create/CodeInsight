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
  vector<long long int> a(5);
  long long int high=10000000;
  long long int pre=0;
  for(long long int i=0; i<5; i++){
    cin>>a.at(i);
    if(a.at(i)%10!=0){
      high=min(a.at(i)%10,high);
      if(high==a.at(i)%10){
        pre=i;
      }
    }
  }
  long long int ans=0;
  for(long long int i=0; i<5; i++){
    if(i==pre){
      ans+=a.at(i);
    }else{
      if(a.at(i)%10==0){
        ans+=a.at(i);
      }else{
        ans+=a.at(i)+(10-a.at(i)%10);
      }
    }
  }
  cout<<ans<<endl;
}