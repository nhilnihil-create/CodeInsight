#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> x(N), dx(N);
  for (int i=0; i<N; i++) {
    cin >> x[i];
  }
  x.push_back(X);
  int mdx=1000000001;
  sort(x.begin(), x.end());
  for (int i=0; i<N; i++) {
    dx[i]=x[i+1]-x[i];
    mdx=min(mdx, dx[i]);
  }
  
  int M=1;
  priority_queue<int,vector<int>, greater<int>> Q;
  
  if (dx.size()==1) {
    M=dx[0];
    goto OUT;
  }
  
  for (int i=2; i<=mdx; i++) {
    if (mdx%i==0) {
      Q.push(i);
    }
  }
  
  while (Q.size()>0) {
    int q=Q.top();
    Q.pop();
    while (true) {
      int fin=0;
      for (int i=0; i<N; i++) {
        if (dx[i]%q!=0) {
          fin=1;
          break;
        }
      }
      if (fin==1) {break;}
      for (int i=0; i<N; i++) {
        dx[i]/=q;
      }
      M*=q;
    }
  }
OUT:
  cout << M << endl;
}
