#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
  vector<int> N(4);
  rep(i, 4){
    cin >> N.at(i);
  }
  vector<int> a = {1, 9, 7, 4};
  rep(i, 4){
    if(count(N.begin(), N.end(), a.at(i)) != 1){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}