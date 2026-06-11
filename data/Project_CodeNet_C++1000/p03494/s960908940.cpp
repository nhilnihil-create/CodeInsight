#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  int non = 100;
  
  for(int i = 0; i < n; i++){//nこの数だけループ
    int a;
    cin >> a;
    while(a %2 == 0){
        a /= 2;
        ans++;
    }
    if(ans < non){
        non = ans;
    }
    ans = 0;
  }
  cout << non << endl;



}

