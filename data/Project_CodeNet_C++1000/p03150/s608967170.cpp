#include<bits/stdc++.h>
using namespace std;



int main(){
  string s;
  cin >> s;
  bool ok=false;
  int n=s.size();
  string key="keyence";
  if(s==key){
    cout << "YES" << endl;
    return 0;
  }

  for(int i=0;i<n;++i){
    for(int j=i;j<n;++j){
      string ss="";
      for(int k=0;k<n;++k){
        if(i<=k & k<=j){
          continue;
        }else{
          ss.push_back(s[k]);
        }
      }
      if(ss==key){
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
