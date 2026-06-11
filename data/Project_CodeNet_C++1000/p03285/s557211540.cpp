#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  cin >> N;

  int cake = 4;
  int donut = 7;

  bool just = false;
  for (int i = 0; i < N / cake + 1; i++)
  {
    for (int j = 0; j < N / donut + 1; j++)
    {
      if (N == i * cake + j * donut){
        just = true;
        break;
      }
    }
    
  }
  cout << (just ? "Yes" : "No") << endl;
}