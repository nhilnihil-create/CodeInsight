#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  int ans10000 = -1;
  int ans5000 = -1;
  int ans1000 = -1;
  for(int i=0;i<=a;i++){
   for(int j=0;i+j<=a;j++){
    int k = a - i - j;
    int total = 10000*i + 5000*j + 1000*k;
    if(total==b){
     ans10000 = i;
     ans5000 = j;
     ans1000 = k;
    }
   }
  }
  cout << ans10000 << " " << ans5000 << " " << ans1000 << endl;
}
