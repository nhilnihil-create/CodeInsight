#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h+2,vector<char>(w+2));
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin >> a[i][j];
    }
  }
  int cnt=0;
  for(int i=1;i<=h;i++){
   for(int j=1;j<=w;j++){
      if(a[i-1][j]!='#' && a[i+1][j]!='#'&& a[i][j-1]!='#' && a[i][j+1]!='#' && a[i][j]=='#')cnt++;
   }
  }
  if(cnt==0)cout << "Yes" << endl;
  else cout << "No" << endl;
}