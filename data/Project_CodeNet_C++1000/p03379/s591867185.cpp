#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;

int main(){
  cout << setprecision(10);
  int N;
  cin >> N;
  vector<ll> A(N), B;

  map<ll, int> m;
  for(int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  B = A;
  sort(A.begin(), A.end());

  for(int i = 0; i < N; i++){
    if(m.count(A.at(i))== 0){
      m[A.at(i)] = i;
    } else { 
      continue;
    }
  }

  for(int i = 0; i < N; i++){
    int j = m[B.at(i)];
    if(j <= (N/2) -1){
      cout << A.at(N/2) << endl;
    } else { 
      cout << A.at(N/2 -1) << endl;
    }
  }
}
