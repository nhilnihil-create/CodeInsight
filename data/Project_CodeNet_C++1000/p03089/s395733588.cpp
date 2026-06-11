#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <set>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
using namespace std;
int main(void){
  int n;
  cin>>n;
  vector<int> s(n);
  for(int i=0; i<n; i++){
    cin>>s.at(i);
  }
  vector<int> ans(n);
  bool can=true;
  for(int i=1; i<=n; i++){
    if(s.at(i-1)>i){
      can=false;
    }
  }

  if(can){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(s.at(s.size()-1-j)==s.size()-j){
          ans.at(ans.size()-1-i)=s.size()-j;
          s.erase(s.begin()+s.size()-1-j);
          break;
        }
      }
    }
    for(int i=0; i<n; i++){
      cout<<ans.at(i)<<endl;
    }
  }else{
    cout<<-1<<endl;
  }
}