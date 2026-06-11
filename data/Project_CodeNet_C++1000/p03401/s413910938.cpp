#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  long long s,cnt=0;
  vector<int> a(n+2);
  for(int j=1;j<n+1;j++){
    cin >> a.at(j);
    cnt += max(a.at(j-1)-a.at(j),a.at(j)-a.at(j-1));
  }
  cnt += max(a.at(n+1)-a.at(n),a.at(n)-a.at(n+1));
  
  for(int j=1;j<n+1;j++){
    s =  max(a.at(j-1)-a.at(j),a.at(j)-a.at(j-1));
    s += max(a.at(j+1)-a.at(j),a.at(j)-a.at(j+1));
    s -= max(a.at(j-1)-a.at(j+1),a.at(j+1)-a.at(j-1));
    cout << cnt -s << endl;
  }
  
  return 0;
}