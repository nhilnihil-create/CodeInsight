#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  string s,t; cin>>s>>t;
  map<char,char> m;
  for(int i=0; i<s.size(); i++){
    if(m[s.at(i)]!=0){
      if(m[s.at(i)]!=t.at(i)){
        cout<<"No"<<endl;
        return 0;
      }
    }
    else{
      m[s.at(i)] = t.at(i);
    }
  }
  set<char> c;
  for(char x='a'; x<='z'; x++){
    if(m[x]==0) continue;
    if(c.count(m[x])){
      cout << "No"<<endl;
      return 0;
    }
    else c.insert(m[x]);
  }
  cout <<"Yes"<<endl;
  
}

