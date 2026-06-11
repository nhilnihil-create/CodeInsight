#include <vector>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <deque>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
#define rep(i, n) for(int i = 0; i<n; i++)
#define rep_s(i, start, n) for(int i= start;  i<n; i++)
#define ALL(a) (a).begin(), (a).end()
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";



int main(void){
  int N, Z, W;
  cin >> N >> Z >> W;
  int a[N];
  rep(i, N) cin >> a[i]; 
  //cout << abs(-1) << endl;
  //cout <<"a[N-1]: " <<  a[N-1] << ", a[N-2]: " <<a[N-2] << endl;
  
  int max_ans1 = abs(a[N-1] - a[N-2]);
  int max_ans2 = abs(a[N-1] - W);
  if (N== 1){
    cout << max_ans2 << endl;
  } else{
   	cout << max(max_ans1, max_ans2) << endl;
  }
}
