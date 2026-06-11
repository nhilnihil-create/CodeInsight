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
  string s;
  cin>>s;
  long long int ans=9999999999;
  for(long long int i=0; i<s.length()-2; i++){
    long long int hoge=(s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0';
    ans=min(ans,abs(753-hoge));
  }
  cout<<ans<<endl;
}