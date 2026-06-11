#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string a,b,c;
  cin >> a >> b >> c;
  vector<vector<int>> s(n,vector<int>(26));
  int sum=0;
  for(int i=0;i<n;i++){
    s[i][a[i]-'a']++;
    s[i][b[i]-'a']++;
    s[i][c[i]-'a']++;
    sum+=3-max({s[i][a[i]-'a'],s[i][b[i]-'a'],s[i][c[i]-'a']});
  }
  cout << sum << endl;
}