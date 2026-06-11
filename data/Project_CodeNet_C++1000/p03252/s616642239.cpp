#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799;


int main(){
  string s, t;
  cin >> s >> t;
  map<char, int> mps, mpt;
  multiset<int> ss, ts;
  bool flag = true;
  for(int i = 0; i < s.size(); i++){
    char c1 = s.at(i), c2 = t.at(i);
    mps[c1]++;
    mpt[c2]++;
  }
  for(pair<char, int> p : mps){
    ss.insert(p.second);
  }
  for(pair<char, int> p : mpt){
    ts.insert(p.second);
  }
  flag = ss == ts;
  
    
  if(flag) cout << "Yes" <<endl;
  else cout << "No" <<endl;
}
  