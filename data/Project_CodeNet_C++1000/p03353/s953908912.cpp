#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  int K;
  cin>>s>>K;
  set<vector<char>> a;
  for(int i=0;i<K;i++){
    for(int j=0;j<s.size()-i;j++){
      vector<char> sub(0);
      for(int k=j;k-j<=i;k++)
        sub.push_back(s.at(k));
      a.insert(sub);
    }
  }
  int j=0;
  vector<char> b;
  for(auto &i:a){
    if(j==K-1){
      b=i;
      break;
    }
    j++;
  }
  for(char &c:b)
    cout<<c;
  cout<<endl;
}