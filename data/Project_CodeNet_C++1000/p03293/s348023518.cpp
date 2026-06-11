#include <bits/stdc++.h>
using namespace std;
int main()
  {string S, T; cin >> S >> T;
  puts((S + S).find(T) != T.npos ? "Yes" : "No");}