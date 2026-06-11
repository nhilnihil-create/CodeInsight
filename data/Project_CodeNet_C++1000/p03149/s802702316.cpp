#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  vector<int> v(4,0);
  cin >> v[0] >> v[1] >> v[2] >> v[3];
  sort(v.begin(), v.end());

  if(v[0] * 1000 + v[1] * 100 + v[2] * 10 + v[3] == 1479){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;

  }
}
