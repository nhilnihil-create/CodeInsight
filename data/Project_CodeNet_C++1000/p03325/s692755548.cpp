#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int ans=0;
  vector<int>a(n);
  for(int i=0;i<n;i++)
    cin >> a.at(i);
  for(int i=0;i<n;i++){
    while(a.at(i)%2==0){
      ans++;
      a.at(i)/=2;
    }
  }
  cout << ans << endl;
  return 0;
}