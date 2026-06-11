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
  long long int start=0;
  long long int end=s.size()-1;
  bool ok=true;
  long long int ans=0;
  while(start<end){
    if(s[start]=='x'&&s[end]=='x'){
      start++;
      end--;
      continue;
    }
    if(s[start]=='x'){
      start++;
      ans++;
      continue;
    }else if(s[end]=='x'){
      ans++;
      end--;
      continue;
    }

    if(s[start]==s[end]){
      start++;
      end--;
    }else{
      ok=false;
      break;
    }
  }
  if(ok){
    cout<<ans<<endl;;
  }else{
    cout<<-1<<endl;
  }
}