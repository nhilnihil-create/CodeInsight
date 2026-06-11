#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<tuple<string,int,int>> A(N);
  for(int i=0; i<N; i++){
    string s;
    int p;
    cin >> s >> p;
    A.at(i) = make_tuple(s,-p,i+1);
  }
  sort(A.begin(),A.end());
  for(int i=0; i<N; i++){
    cout << get<2>(A.at(i)) << endl;;
  }
  return 0;
}