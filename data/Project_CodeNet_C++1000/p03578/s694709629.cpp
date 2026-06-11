#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  int n;
  cin >> n;
  vector<ll> d(n);
  for(int i=0;i<n;i++){
    cin >> d.at(i);
  }
  int m;
  cin >> m;
  vector<ll> t(m);
  for(int i=0;i<m;i++){
    cin >> t.at(i);
  }
  if(n<m)
  cout << "NO" << endl;
  else{
    sort(d.begin(),d.end());
    sort(t.begin(),t.end());
    int k=0;
    for(int i=0;i<m;i++){
      for(int j=k;j<n;j++){
        if(t.at(i)==d.at(j)){
          k=j+1;
          break;
        }
        else if(j==n-1){
          cout << "NO" << endl;
          return 0;
        }
      }
    }
    cout << "YES" << endl;
  }
}

