#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,H,W;
  cin >> N >> H >> W;
  int sum=0;
  for(int i=0;i<N;i++){
    int a,b;
    cin >> a >> b;
    sum+=min((a/H)*(b/W),1);
  }
  cout << sum;
}
