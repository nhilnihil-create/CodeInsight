#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N;
  cin >> N;
  vector<int> A(N+2, 0); 
  for (int i=1; i<=N; i++) {
    cin >> A[i];
  }
  
  int S=0;
  for (int i=0; i<=N+1; i++) {
    S+=abs(A[i]-A[i-1]);
  }
  
  for (int i=1; i<=N; i++) {
    int s=S-abs(A[i]-A[i-1])-abs(A[i+1]-A[i])+abs(A[i+1]-A[i-1]);
    cout << s << endl;
  }
  
}
 