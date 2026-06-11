#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define puts(i) cout << i << endl
#define INF INT_MAX;
#define INFL LLONG_MAX;
typedef long long ll;
using namespace std;

int main(){
  int N; cin >> N;
  int w = 1,odd=1;
  rep(i,N){
    int x; cin >> x;
    w*=3;
    if(x%2==0) odd*=2;
  }
  cout << w-odd << endl;
}