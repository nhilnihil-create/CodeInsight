#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;
const ll MOD = 1000000007;

int main(){
  int r;
  cin >> r;
  if(r<1200){
    cout << "ABC" <<endl;
  }else if(r < 2800){
    cout << "ARC" <<endl;
  }else{
    cout << "AGC" <<endl;
  }
}
