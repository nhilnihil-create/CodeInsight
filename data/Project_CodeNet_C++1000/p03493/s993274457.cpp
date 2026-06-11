#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
  	cin >> n;
  	int a3 = n / 100;
  	int a2 = (n % 100) / 10;
    int a1 = ((n % 10) % 10);
  	cout << a3 + a2 + a1 << endl;
      
}