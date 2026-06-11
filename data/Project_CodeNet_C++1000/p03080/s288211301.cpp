#include<iostream>
using namespace std;

int main() {
  int N; cin >> N;
  string S; cin >> S;
  int r=0;
  for (char c : S) {
	if (c=='R') r += 1;
  }
  if (r > N-r) 
    cout << "Yes" << endl;
  else
	cout << "No" << endl;
}