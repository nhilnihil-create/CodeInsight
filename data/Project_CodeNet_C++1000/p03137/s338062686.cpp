#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)

typedef long long ll;

int main(){
 int n, m;
 cin >> n >> m;
 vector<int> x(m, 0);
 rep(i, m) cin >> x.at(i);
 sort(x.begin(), x.end());
 vector<int> kyori(m-1,0);
 rep(i, m-1) kyori.at(i) = x.at(i+1) - x.at(i);
// rep(i, m-1) cout << kyori.at(i) << endl;
 sort(kyori.begin(), kyori.end());

 ll ans = 0;
 rep(i, max(m-n, 0)){
   ans += kyori.at(i);
 }
 cout << ans;
}
