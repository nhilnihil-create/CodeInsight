#include <bits/stdc++.h>
#define rep(j, n) for (int j=0; j<(int)(n); j++)
using namespace std;
using ll = long long;
using P=pair<int,int>;
using V=vector<vector<int>>;

int main(){
  int N;
  cin >> N;

  vector <tuple<string, int, int>> A;

  for( int i=1; i<=N; i++){
    string S;
    int P;
    cin >> S >> P;
    P = -P;
    
    A.push_back(tie(S, P, i));
  }

  sort(A.begin(), A.end());

  rep(i, N){
    cout << get<2>(A[i]) << endl;
  }
}
