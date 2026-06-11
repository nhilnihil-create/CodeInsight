#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  string S;
  int A, B;
  cin >> A >> B >> S;

  bool post = true;
  if (S.at(A) != '-') post = false;
  for (int i = 0; i < A + B + 1; i++)
  {
    if (!(isdigit(S.at(i))) && i != A){
      post = false;
    } 
  }
  cout << (post ? "Yes" : "No") << endl;
}