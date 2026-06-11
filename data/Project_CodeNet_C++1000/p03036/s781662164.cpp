#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int r,d,x; cin >> r >> d >> x;

  for(int i = 0; i < 10; i++){
    x = r * x - d;
    cout << x << endl;
  }
}
