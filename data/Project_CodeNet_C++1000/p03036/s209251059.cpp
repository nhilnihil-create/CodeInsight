#include <bits/stdc++.h>
#define MOD (long long)(1E9+7)
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int r,d,x;
	cin >> r >> d >> x;
  	rep(i, 10)
    	cout << (x=r*x -d)<< endl;
}
