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
  long long int streak=0;
  long long int longest=0;
  for(long long int i=0; i<s.size(); i++){
    if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T'){
      streak++;
    }else{
      longest=max(longest,streak);
      streak=0;
    }
  }
  longest=max(longest,streak);
  cout<<longest<<endl;
}