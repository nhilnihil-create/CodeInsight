#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
     ifstream in("input.txt");
     cin.rdbuf(in.rdbuf());
  //*/
  int N, M, X;
  cin >> N >> M >> X;
  int cost1 = 0, cost2 = 0;
  for(int i = 0; i < M; i++){
    int a;
    cin >> a;
    if(a < X){
      cost1++;
    }else{
      cost2++;
    }
  }
  cout << min(cost1, cost2)<<endl;
}
