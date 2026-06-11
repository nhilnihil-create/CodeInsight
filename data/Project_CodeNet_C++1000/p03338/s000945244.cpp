#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  
  int ans=0;
  
  for(int i=0;i<n;i++){
    vector<int> a(26);
    vector<int> b(26);
    for(int j=0;j<i;j++) a.at(s.at(j)-'a')++;
    for(int j=i;j<n;j++) b.at(s.at(j)-'a')++;
    
    int k=0;
    for(int j=0;j<26;j++){
      if(a.at(j)*b.at(j)) k++;
    }
    
    ans=max(ans,k);
  }
  cout << ans << endl;
}