#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

string my_pair(string S) {
  if (S == "A") return "T";
  if (S == "T") return "A";
  if (S == "C") return "G";
  if (S == "G") return "C";
}

int main(){
  string T;
  cin >> T;
  
  cout << my_pair(T) << endl;

}
