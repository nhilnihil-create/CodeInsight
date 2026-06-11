#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
	int n,x;
	cin >> n >> x;
	int kona = 0;
	int mini = 2000000;

	rep(i, n){
		int a;
		cin >> a;
		x -=a;
		mini = min(mini, a);
	}

	int ans = 0;
	while(mini <= x){
		ans++;
		x -= mini;
	}

	cout << n+ans << endl;
}