#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  double T;
  T=0;
  for (int i=0;i<N;i++) {
    double A;
	string S;
	cin >> A >> S;
	if (S=="JPY") {T+=A;} else {T+=A*380000;}
	
  }
  cout << fixed << setprecision(10) << T << endl;
  
}