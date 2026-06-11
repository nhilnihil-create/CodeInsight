#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, A, tmp;
  cin >> N >> A;
  tmp = N % 500;
  if(tmp <= A) cout << "Yes";
  else cout << "No";
}