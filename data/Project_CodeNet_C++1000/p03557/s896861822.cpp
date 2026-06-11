#include<bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
long long dp[100010];
template<class T> inline bool chmax(T& a, T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b){if(a>b){a=b;return 1;}return 0;}
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a)  (a).begin(),(a).end()
//bitset<64>(x).count()
//fixed << setprecision(15) << 

int binary_search(vector<int> a, int key) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (a[mid] >= key) ok = mid;
        else ng = mid;
    }
    return ng;
}

int main (){
  int n, tmp;
  cin >> n;
  vector<int> a, b, c;
  rep(i,n){
    cin >> tmp;
    a.push_back(tmp);
  }
  rep(i,n){
    cin >> tmp;
    b.push_back(tmp);
  }
  rep(i,n){
    cin >> tmp;
    c.push_back(tmp);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  long long ans = 0;
  rep(i,n){
    ans += (lower_bound(all(a), b[i]) - a.begin())*(c.end() -upper_bound(all(c), b[i]) );
    //cout << (lower_bound(all(a), b[i]) - a.begin())<< " " << (c.end() -upper_bound(all(c), b[i]) )<< endl;
  }
  cout << ans << endl;
}