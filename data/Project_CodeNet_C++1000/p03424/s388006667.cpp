#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++){
  	string s;
    cin >> s;
    if (s == "Y"){
    cout << "Four" << endl;
    break;
    }
    if(s == "P" || s == "W" || s == "G"){
     if(i == N - 1){
     cout << "Three" << endl;
     }
     }
    }
}