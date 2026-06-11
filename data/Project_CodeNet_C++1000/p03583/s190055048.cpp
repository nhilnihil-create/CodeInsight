#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  ll N;
  cin >> N;
  for(ll x = 1; x <= 3500; x++){
    for(ll y = 1; y <= 3500; y++){
      ll left = 4*x*y - N * y - N * x;
      ll right = N * x * y;
      ll z;
      if(left > 0 && right % left == 0){
        z = right / left;
        cout << x << " " << y << " " << z << endl;
        return 0;
      }
    }
  }
}
