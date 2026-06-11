#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4


int main(){
  int N; cin >> N;
  string S; cin >> S;

  int cnt = 0, max_cnt = 0; 
  for (int i=0;i<N;i++){
    set<char> L;
    cnt = 0;
    for (int j=0;j<N;j++){
      if (j<=i) L.insert(S[j]);
      else if (L.count(S[j])){
        cnt++;
        L.erase(S[j]);
      }
      
    }
    max_cnt = max(max_cnt, cnt);
  }

  cout << max_cnt << endl;

  return 0;
}