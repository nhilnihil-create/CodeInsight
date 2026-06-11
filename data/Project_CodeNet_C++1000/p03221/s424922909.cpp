#include <iostream>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  int P[100000], Y[100000];
  vector<int > ids[100001];
  for (int i = 0; i < M; i++){
    cin >> P[i] >> Y[i];
    ids[P[i]].push_back(Y[i]);
  }

  for (int i = 0; i < N; i++){
    sort(ids[i+1].begin(),ids[i+1].end());
  }

  for (int i = 0; i < M; i++){
    cout << setfill('0') << right << setw(6) << P[i];
    cout << setfill('0') << right << setw(6) << lower_bound(ids[P[i]].begin() ,ids[P[i]].end() , Y[i])-ids[P[i]].begin()+1 << endl;
  }
  
  
  
}
