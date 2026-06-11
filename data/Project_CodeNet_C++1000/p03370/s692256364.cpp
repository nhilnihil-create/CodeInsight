#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,X;
  cin >> N >> X ;
  vector<int> m(N);
  for (int i=0;i<N;i++){
    cin >> m[i] ;
    X-=m[i];
  }
  sort(m.begin(),m.end());
  int answer=N+X/m[0];
  
    cout<< answer <<endl;
}
