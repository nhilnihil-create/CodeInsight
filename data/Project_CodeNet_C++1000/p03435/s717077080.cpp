#include <iostream>
#include <vector>
using namespace std;
#define N 3

int main()
{
  int c[N][N];

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> c[i][j];
    }
  }

  int b[N];
  for(int i=0;i<N;i++){
    b[i] = c[0][i];
  }

  int a[N];
  a[0] = 0;
  a[1] = c[1][0] - b[0];
  a[2] = c[2][0] - b[0];

  for(int i=1;i<N;i++){
    for(int j=1;j<N;j++){
      if(c[i][j] != a[i] + b[j]){
        cout << "No\n";
        return 0;
      }
    }
  }

  cout << "Yes\n";
}
