#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  int a[4];
  a[0] = N % 10; N /= 10;//一の位を取り出す
  a[1] = N % 10; N /= 10;
  a[2] = N % 10; N /= 10;
  a[3] = N % 10; N /= 10;//千の位を取り出す
  if (a[0] == a[1] && a[1] == a[2] || a[1] == a[2] && a[2] == a[3]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }

}
