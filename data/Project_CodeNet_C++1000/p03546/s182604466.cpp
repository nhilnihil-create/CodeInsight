#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int matrix[10][10];
vector<int> minMap(10, 10000);

int main(){
  int h, w;
  cin >> h >> w;
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      cin >> matrix[i][j];
    }
  }
  for(int k=0; k<10; k++){
    for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
        matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
      }
    }
  }
  int sum = 0;
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      int num;
      cin >> num;
      if(num != 1 && num != -1) sum += matrix[num][1];
    }
  }
  cout << sum << endl;
  return 0;
}
  