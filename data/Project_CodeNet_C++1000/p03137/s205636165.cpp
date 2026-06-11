#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> x(m);
  for(int i=0;i<m;i++){
    cin >> x.at(i);
  }
  if(n>=m){
    cout << 0 << endl;
    return 0;
  }
  else{
    sort(x.begin(),x.end());
    int sa=x.at(m-1)-x.at(0);
    vector<int> a(m-1);
    for(int i=0;i<m-1;i++){
      a.at(i)=x.at(i+1)-x.at(i);
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int sum=0;
    for(int i=0;i<n-1;i++){
      sum+=a.at(i);
    }
    cout << sa-sum << endl;
  }
}

