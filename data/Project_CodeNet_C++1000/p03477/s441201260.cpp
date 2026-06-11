#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,f,j;
  cin >> N >> A >>f>>j;
  if (N+A>f+j) {
    cout <<"Left"<< endl;
  }
  else if(N+A==f+j)cout<<"Balanced"<<endl;
  else cout<<"Right"<<endl;
}