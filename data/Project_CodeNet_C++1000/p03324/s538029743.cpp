#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main(){
	cin.tie(0);
  	ios::sync_with_stdio(false);
  	int d = 0, n = 0;
  	long long power = 0;
  	cin >> d >> n;
  	if(n == 100)
		n += 1;
    switch(d){
      case 0: power = 1; break;
      case 1: power = 100; break;
      case 2: power = 10000;
    }
  	
  	cout << power*n << endl;
	return 0;
}