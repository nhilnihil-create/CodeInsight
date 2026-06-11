#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
#define erep(i,n) for(int i = 0;i<=n;i++)
#define rep1(i,n) for(int i = 1;i<n;i++)
#define erep1(i,n) for(int i = 1;i<=n;i++)
typedef long long ll;
#define vint vector<int>
#define vstring vector<string>
#define vll vector<ll>
#define vbool vector<bool>
#define INF 100000000

int main(){
  int n;
  cin >> n;
  vector<vint> red(n,vint(n));
  vector<vint> blue(n,vint(n));
  int count = 0;
  rep(i,n) cin >> red[i][1] >> red[i][0];
  rep(i,n) cin >> blue[i][0] >> blue[i][1];
  sort(red.begin(),red.end());
  sort(blue.begin(),blue.end());
  reverse(red.begin(),red.end());
  rep(i,n){
    bool key = false;
    rep(j,n){
      if(0 < blue[i][0] && 0 < blue[i][1]){
        if(red[j][1] < blue[i][0] && red[j][0] < blue[i][1]){
          red[j][0] = INF;
          red[j][1] = INF;
          count++;
          key = true;
          break;
        }
      }
    }
  }
  cout << count << endl;
}