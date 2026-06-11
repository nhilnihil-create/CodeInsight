#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int r, d, x;
  cin >> r >> d >> x;

  rep(i, 10){
    x*=r;
    x-=d;
    cout << x << endl;
  }

  return 0;
}