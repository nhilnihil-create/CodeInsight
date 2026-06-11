#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin >> N >> A >> B;
  int ua=0,ab=0,ob=0;
  for(int i=0;i<N;i++){
    int x;
    cin >> x;
    if(x<=A)ua++;
    else if(x>=B+1)ob++;
    else ab++;
  }
  cout << min({ua,ab,ob});
}

