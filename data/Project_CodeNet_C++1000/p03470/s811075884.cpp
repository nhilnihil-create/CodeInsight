#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> rice(N);
  for (int i = 0; i < N; i++) {
  	cin >> rice.at(i);
  }
  
  int n = 0;
  
  for (int i = 0; i < N; i++) {
  	if (rice.at(i) == 0){
    	continue;
    }
    else {
    	for (int j = 0; j < N; j++){
        	if (i == j) {
            	continue;
            }
          	else if (rice.at(j) == rice.at(i)) {
            	rice.at(j) = 0;
              	n++;
            }
        }
    }
  }
  
  cout << N -n;
  
}