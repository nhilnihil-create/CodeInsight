#include<bits/stdc++.h>
using namespace std;
int main(){
  string s[110];
  map<string,bool> mp;
  int n,i;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> s[i];
    if(mp[s[i]]==true){
      cout << "No" << endl;
      return 0;
    }
    else{
      mp[s[i]]=true;
    }
  }
  for(i=1;i<n;i++){
    if(s[i-1][s[i-1].size()-1]!=s[i][0]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}