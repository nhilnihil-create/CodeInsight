#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;
  char g[100][100];
  fill(g[0],g[50],'#');
  fill(g[50],g[100],'.');

  for(int i=1 ; i<=A-1 ; i++){
    int tmp1 = i/50;
    int tmp2 = i%50;
    int h = 2*tmp1 + 1;
    int w = 2*tmp2 - 1;
    g[h][w] = '.';
  }

  for(int i=1 ; i<=B-1 ; i++){
    int tmp1 = i/50;
    int tmp2 = i%50;
    int h = 2*tmp1 + 51;
    int w = 2*tmp2 -1;
    g[h][w] = '#';
  }

  cout << 100 << " " << 100 << endl;
  for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
      cout << g[i][j];
    }
    cout << endl;
  }

  return 0;
}