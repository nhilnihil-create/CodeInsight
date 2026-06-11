#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int h,w;
  cin >> h >> w;
  vector<string> s(h+2);
  for(int i=0;i<w+2;i++){
    s.at(0)+='.';
    s.at(h+1)+='.';
  }
  for(int i=1;i<h+1;i++){
    s.at(i)='.';
    string t;
    cin >> t;
    s.at(i)+=t;
    s.at(i)+='.';
  }
  
  int ans=1;
  
  for(int i=1;i<h+1;i++){
    for(int j=1;j<w+1;j++){
      if(s.at(i).at(j)=='#'){
        ans*=(s.at(i+1).at(j)=='#'||s.at(i-1).at(j)=='#'||s.at(i).at(j+1)=='#'||s.at(i).at(j-1)=='#');
      }
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}