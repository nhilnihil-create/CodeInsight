#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int a[5];
  for(int i=0; i<5; i++){
    cin >> a[i];
  }
  int k;
  cin >> k;
  string ans = "Yay!";
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      int tmp = abs(a[i]-a[j]);
      if(tmp>k) ans = ":(";
    }
  }
  cout << ans << endl;
  return 0;
}
