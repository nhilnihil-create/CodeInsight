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
  vector<string> s(n);
  long long int lasta=0;
  long long int firstb=0;
  long long int both=0;
  long long int ab=0;
  for(long long int i=0; i<n; i++){
    cin>>s.at(i);
    for(long long int j=0; j<s.at(i).size()-1; j++){
      if(s.at(i)[j]=='A'&&s.at(i)[j+1]=='B'){
        ab++;
      }
    }
    if(s.at(i)[0]=='B'&&s.at(i)[s.at(i).size()-1]=='A') {
      both++;
      continue;
    }
    if(s.at(i)[0]=='B') firstb++;
    if(s.at(i)[s.at(i).size()-1]=='A') lasta++;
  }

  while(true){
    if(lasta>0&&both>0){
      ab++;
      both--;
    }else if(firstb>0&&both>0){
      ab++;
      both--;
    }else if(lasta>0&&firstb>0){
      ab++;
      lasta--;
      firstb--;
    }else if(both>=2){
      ab++;
      both--;
    }else{
      break;
    }
  }
  cout<<ab<<endl;
}