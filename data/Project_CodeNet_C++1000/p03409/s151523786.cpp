#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using P = pair<int, int>;

bool sortbysec(const P &p, const P &q){
  return p.second > q.second;
}

int main(){
  int n;
  cin >> n;
  vector<P> A;
  for(int i = 0; i < n; ++i){
    int a, b;
    cin >> a >> b;
    A.push_back(P(a, b));
  }

  vector<P> B;
  for(int i = 0; i < n; ++i){
    int c, d;
    cin >> c >> d;
    B.push_back(P(c, d));
  }

  sort(B.begin(), B.end()); 
  sort(A.begin(), A.end(), sortbysec); 

  vector<bool> used(n, false);
  for(int i = 0; i < n; ++i){
    int c = B[i].first;
    int d = B[i].second;
    for(int j = 0; j < n; ++j){
      int a = A[j].first;
      int b = A[j].second;
      if(!used[j] && a < c && b < d){
        used[j] = true;
        break;
      }
    }
  }

  int count = 0;
  for(int i = 0; i < n; ++i){
    if(used[i])++count;
  }

  cout << count << endl;
}
