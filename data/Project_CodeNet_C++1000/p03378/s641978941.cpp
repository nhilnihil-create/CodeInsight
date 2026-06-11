#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m, x;
  cin >> n >> m >> x;
  int down = 0, up = 0;
  for(int i = 0 ; i < m; i++){
    int a;
    cin >> a;
    if(x < a) up++;
    else down++;
  }
  cout << min(up, down) << endl;
}