#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans=1;
  vector<string> w(n);
  for(int i=0;i<n;i++){
    cin >> w.at(i);
    if(i!=0){
      ans*=(w.at(i-1).at(w.at(i-1).size()-1)==w.at(i).at(0));
    }
  }
  sort(w.begin(),w.end());
  for(int i=1;i<n;i++)
    ans*=(w.at(i-1)!=w.at(i));
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}