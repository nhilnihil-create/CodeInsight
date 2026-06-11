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
int s[100000],t[100000],c[100000]; 
int sm[200002]; 
int tt[200002]; 
/*
typedef struct  a {
  int num;
  int count;
};
*/
int main(void){
  int N;
  cin >> N;
  int a[N+1];
  int min_num=1e+8, max_num = -1e+8;
  int max_index, min_index;
  int count, count_sousa = 0;
  rep_s(i,1, N+1) {
    cin >> a[i]; 
    if (max_num < a[i]){
      max_num = a[i];
      max_index = i;
    }
    if (min_num > a[i]){
      min_num = a[i];
      min_index = i;
    }
  }
  
  if (min_num >=0){
    cout << N-1 << endl;
    rep_s(i,1, N){
      cout << i << " " <<i+1 << endl;
    }
  } else if (max_num <=0){
    count = N;
    cout << N-1 << endl;
    rep(i, N-1){
      cout << count-i << " " << count-i-1 << endl;
    }
  } else{
    if (abs(max_num)>=abs(min_num)){
      cout << 2*N -1 << endl;
      rep_s(i, 1, N+1) {
        cout << max_index <<" " << i << endl;
      }
      rep_s(i,1, N){
      cout << i << " " <<i+1 << endl;
    }
    } else {
      cout << 2*N-1 <<endl;
      rep_s(i, 1, N+1){
        cout << min_index << " " << i << endl;
      }
      count = N;
      rep(i, N-1){
        cout << count-i << " " << count-i-1 << endl;
      }
    }
  }
}
