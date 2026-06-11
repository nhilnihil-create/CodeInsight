#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 305;

char gr[N][N];
int n;
char nw[N][N];

bool check(int x, int y){
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ; j < n ; j ++ ){
      nw[(i + x) % n][(j + y) % n] = gr[i][j];
    }
  }
  for(int i = 0 ; i < n ; i ++ ){
    for(int j = 0 ; j < n ; j ++ ){
      if(nw[i][j] != nw[j][i])
        return false;
    }
  }
  return true;
}

int main(){
  fastIO;
  cin >> n;
  for(int i = 0 ; i < n ; i ++ ){
    for(int j = 0 ; j < n ; j ++ ){
      cin >> gr[i][j];
    }
  }
  int res = 0;
  for(int i = 0 ; i < n ; i ++ )
    res += check(0,i);
  cout << res * n;
  return 0; 
}