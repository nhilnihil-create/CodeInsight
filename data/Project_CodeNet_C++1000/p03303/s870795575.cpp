#include <bits/stdc++.h>
using namespace std;

int main() {
	string N;
	cin >> N;
  
  	int w;
  	cin >> w;
	
  	int i = 0;
  	while(i < N.size()){
  	  cout << N.at(0+i);
      i += w;
    }
  cout << endl;
}