#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  vector<vector<int>> plan(n,vector<int>(3));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 3; j++){
      cin >> plan.at(i).at(j);
    }
  }
  
  bool ans=true;

  int nx=0;
  int ny=0;
  int nt=0;

  for (vector<int> v: plan){
    int t=v.at(0);
    int x=v.at(1);
    int y=v.at(2);

    if(t-nt<abs(x-nx)+abs(y-ny)||(t-nt)%2!=(abs(x-nx)+abs(y-ny))%2){
      cout << "No" << endl;
      ans=false;
      break;
    }

    nx=x;
    ny=y;
    nt=t;
  }

  if(ans){
    cout << "Yes" << endl;
  }
}