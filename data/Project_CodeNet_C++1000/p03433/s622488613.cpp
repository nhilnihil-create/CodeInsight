#include <bits/stdc++.h>
using namespace std;


int main()
{
  int A, N;
  cin >> N >> A;

  int ret = N % 500;
  if(ret > A){
    cout << "No" << endl;
  }else if(ret <= A) {
    cout << "Yes" << endl;
  }
}
