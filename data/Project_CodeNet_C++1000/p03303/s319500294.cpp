#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  string s;
  cin >> s;
  int w;
  cin >> w;
  int n=s.size();
  for(int i=0;i<n;i=i+w){
    cout << s[i];
  }
  cout << endl;
  return 0;
}
