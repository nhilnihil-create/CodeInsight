#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int s;
  cin >> s;

  set<int> set;
  set.insert(s);
  int cnt = 1;
  int a;

  while(true){
    if (cnt == 1) a = s;
    if (a % 2 == 0){
      a /= 2;
    }
    else
    {
      a = 3 * a + 1;
    }
    cnt += 1;
    if (set.count(a)) break;
    set.insert(a);
  }
  
  cout << cnt << endl;
}