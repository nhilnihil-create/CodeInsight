#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans=0;
  vector<int>kati(n);
  vector<int>kane(n);
  for(int i=0;i<n;i++)
    cin >> kati.at(i);
  for(int i=0;i<n;i++)
    cin >> kane.at(i);
  for(int i=0;i<n;i++){
    if(kati.at(i)-kane.at(i)>0)
      ans+=kati.at(i)-kane.at(i);
  }
  cout << ans << endl;
  return 0;
}