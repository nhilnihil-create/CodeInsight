#include<iostream>
#include<map>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int N = S.size();
  map<char, char> M;
  bool transformable = true;
  for (int i = 0; i < N; i++) {
    if (M.find(S[i]) != M.end() && M[S[i]] != T[i]) { transformable = false; break; }
    M[S[i]] = T[i];
  }
  M.clear();
  for (int i = 0; i < N; i++) {
    if (M.find(T[i]) != M.end() && M[T[i]] != S[i]) { transformable = false; break; }
    M[T[i]] = S[i];
  }
  cout << (transformable ? "Yes" : "No") << endl;
}