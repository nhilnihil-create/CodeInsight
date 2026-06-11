#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int>a(3);
  for(int i=0;i<3;i++){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  int count=0;
  for(int i=1;i<3;i++){
    count+=(a[i]-a[i-1]);
  }
  cout << count << endl;
}