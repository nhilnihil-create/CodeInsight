#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int f(int x){
	if(x%10 == 0) return x;
	else return ((x/10)+1)*10;
}

int main(){
	vector<int> a(5);
	rep(i,5) cin >> a[i];
	int min_num = 5;
	int min_minu = 10;
	rep(i,5){
		if(a[i] % 10 == 0) continue;
		if(min_minu > a[i] % 10){
			min_minu = a[i] % 10;
			min_num = i;
		}
	}
	int time = 0;
	rep(i,5){
		if(i == min_num) time += a[i];
		else time += f(a[i]);
	}
	cout << time << endl;
}