#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    if(i!=0) a.at(i)=a.at(i-1)+x;
    else a.at(i)=x;
  }
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    if(i!=0) b.at(i)=b.at(i-1)+x;
    else b.at(i)=x;
  }
  
  int ans=a.at(0)+b.at(n-1);
  
  for(int i=1;i<n;i++){
   ans=max(ans,a.at(i)+b.at(n-1)-b.at(i-1));
  }
  
  cout << ans << endl;
}