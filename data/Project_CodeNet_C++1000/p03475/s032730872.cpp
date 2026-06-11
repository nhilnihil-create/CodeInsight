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
  int N; cin >> N;
  int C[N-1], S[N-1], F[N-1];
  rep(i,N-1) cin >> C[i] >> S[i] >> F[i];

  rep(i,N){
    int now = 0;
    for (int j = i;j<N-1;j++){
      if (now<=S[j]) now = S[j];
      else if (now%F[j]!=0) now += F[j]-(now%F[j]);
      
      now += C[j];
    }
    cout << now << endl;
  }

  return 0;
}
