#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int n=s.size();
  string target="keyence";
  if(s==target){
    cout << "YES" << endl;
    return 0;
  }
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      string S="";
      for(int k=0;k<n;k++){
        if(i<=k && k<=j)continue;
        S.push_back(s[k]);
      }
      if(target==S){
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}