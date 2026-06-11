#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  vector <int> vec(N);
  //int a[N];
  rep(i,N) cin >> vec.at(i);//a_i

  vector <int> kaisuu(N);//a_iが2で割れる回数
  rep(i,N){
    //int kaisuu = 0;
    for (; vec.at(i) % 2 == 0; vec.at(i) /= 2){
      kaisuu.at(i) += 1;
    }
  }

  sort(kaisuu.begin(), kaisuu.end());
  cout << kaisuu.at(0) << endl;

}
