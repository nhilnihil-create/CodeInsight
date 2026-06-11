#include <bits/stdc++.h>
using namespace std;

int main(void){
    
  int N,max;
  string S;
  cin >> N >> S;

  for(int i=1;i<N;i++){
      string l,r;
      set<char> set_l;
      set<char> set_r;
      set<char> result;
      
      l = S.substr(0,i);
      r = S.substr(i);
     
      for(int j=0;j<l.size();j++) set_l.insert(l[j]);
      for(int j=0;j<r.size();j++) set_r.insert(r[j]);
      
      set_intersection(set_l.begin(),set_l.end(),set_r.begin(), set_r.end(),inserter(result, result.end()));
      if(i == 1) max = result.size();
      else{ if(max < result.size()) max = result.size();}
  }
  
  cout << max << endl;
}