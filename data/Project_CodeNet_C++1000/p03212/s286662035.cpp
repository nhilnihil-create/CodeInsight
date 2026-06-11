#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  int ans = 0;
  for(int i = 1; i < 10; i++){
    for(int j = 1; j < 10; j++){
      for(int k = 1; k < 10; k++){
        if(i+j+k < 11){
          vector<string> tmp;
          rep(a,i) tmp.push_back("3");
          rep(a,j) tmp.push_back("5");
          rep(a,k) tmp.push_back("7");
          do{
            string res = "";
            for(string x : tmp) res += x;
            if(stoll(res) <= n) ans++;
          }while(next_permutation(all(tmp)));
        }
      }
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}
