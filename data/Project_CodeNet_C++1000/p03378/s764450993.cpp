#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  
  int A;
  vector<int> box(101, 0);
  for (int i=0; i<M; i++) {
    cin >> A;
    box.at(A) = 1;
  }
  
  //現在値からマスNまでのコスト
  int cost1=0;
  for (int i=X; i<N; i++) {
    cost1 += box.at(i);
  }
  //現在値からマス0までのコスト
  int cost2=0;
  for (int i=X; i>0; i--) {
    cost2 += box.at(i);
  }

  //小さいほうを出力
  cout << min(cost1, cost2) << endl;
  return 0;
}