#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,m,i,j;
  cin >> n;
  vector<int> d(n);
  for(i=0;i<n;i++){
    cin >> d.at(i);
  }
  cin >> m;
  vector<int> t(m);
  for(i=0;i<m;i++){
    cin >> t.at(i);
  }
  sort(d.begin(),d.end());
  sort(t.begin(),t.end());
  j=0;
  for(i=0;i<n;i++){
    if(j<m&&t.at(j)==d.at(i)){
      j++;
    }
  }
  
  if(j==m){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}