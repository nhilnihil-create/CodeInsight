#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int t = 0,x = 0,y = 0;
  REP(i,n){
    int ti,xi,yi;
    cin >> ti >> xi >> yi;
    if(abs(ti - t) < (abs(xi - x)+abs(yi - y))){
	 cout << "No" << endl;
      return 0;
    }
    else{
      if((abs(ti - t)-abs(xi - x)-abs(yi - y)) % 2 == 0){
        t = ti;
        x = xi;
        y = yi;
        continue;
      }
      else{
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}
