#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  int N, M; cin >> N >> M;
  int K, A;
  int a[M]={};
  rep(i,N){
    cin >> K;
    rep(j,K){
      cin >> A;
      A--;
      a[A]++;
    }
  }

  int cnt = 0;
  rep(i,M) cnt += (a[i]==N);
  // rep(i,M) cout << a[i] << endl; 

  cout << cnt << endl;

  // cout << fixed << setprecision(6);
  return 0;
}
