#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end());
#define vecmin(A) *min_element(A.begin(),A.end());
#define vecmax(A) *max_element(A.begin(),A.end());
typedef long long ll;
typedef vector<int> vec;

int main(){
  int r;
  cin >> r;
  if(r<1200){
    cout << "ABC" << endl;
    return 0;
  }
  if(r<2800){
    cout << "ARC" << endl;
    return 0;
  }
  cout << "AGC" << endl;
}