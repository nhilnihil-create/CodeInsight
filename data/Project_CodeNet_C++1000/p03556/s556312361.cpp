#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
   	int n, i = 0;
  	cin >> n;
  	while(true){
      	i++;
    	if(i*i > n){
        	cout << (i-1)*(i-1) << endl;
          	return 0;
        }
    }
    return 0;
}