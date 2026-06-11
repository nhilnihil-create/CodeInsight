#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A , C , D;
  cin >> N >> A >> C >> D;

  if (N+A==C+D) {
    cout << "Balanced" << endl;
  }
  else if  (N+A>C+D){
    cout <<"Left" << endl;
  }
  else {
   cout <<"Right" << endl;
  }
}