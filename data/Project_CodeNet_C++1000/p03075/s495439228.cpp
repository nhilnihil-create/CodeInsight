#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(void){
  int a[6];
  rep(i,6) cin >> a[i];
  for(int i = 0; i < 5; i++){
    for(int j = i+1; j < 6; j++){
      if(a[j]-a[i] > a[5]){
        cout << ":(" << endl;
        return 0;
      }
    }
  }
  cout << "Yay!" << endl;
  return 0;
}
