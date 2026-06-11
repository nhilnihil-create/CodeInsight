#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl

const int maxn = 100;

int a,b;

char g[maxn][maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

  cin>>a>>b;
  for (int i=0; i<50; i++) {
    for (int j=0; j<100; j++) {
      g[i][j]='.';
    }
  }
  a--;
  for (int i=50; i<100; i++) {
    for (int j=0; j<100; j++) {
      g[i][j]='#';
    }
  }
  b--;

  for (int i=0; i<50 && b>0; i+=2) {
    for (int j=0; j<100 && b>0; j+=2) {
      g[i][j]='#'; b--;
    }
  }

  for (int i=99; i>=50 && a>0; i-=2) {
    for (int j=0; j<100 && a>0; j+=2) {
      g[i][j]='.'; a--;
    }
  }

  cout<<"100 100\n";
  for (int i=0; i<100; i++) {
    for (int j=0; j<100; j++) {
      cout<<g[i][j];
    }
    cout<<'\n';
  }

  
  return 0;
}
