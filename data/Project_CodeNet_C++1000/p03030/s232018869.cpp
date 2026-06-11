#include <bits/stdc++.h>
using namespace std;

bool my_compare(pair<string,int> a, pair<string,int> b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    
    if(a.second != b.second){
        return a.second > b.second;
    }else{
        return true;
    }
}

int main(){
  int N,b;
  string a;
  using pr = pair<string,int>;
  vector<pr> vc;
  vector<pr> cp;
  cin >> N;
  
  for(int i = 0; i < N; i++){
    cin >> a >> b;
  	vc.push_back(make_pair(a,b));
  }
  
  cp = vc;
  
  sort(vc.begin(),vc.end(),my_compare);
  
  
  for(int i = 0; i < vc.size(); i++){
      for(int j = 0; j < vc.size(); j++){
          if(vc.at(i) == cp.at(j))
            cout << j + 1 << endl;
      }
      
  }
  
  return 0;
}