#include<bits/stdc++.h>
using namespace std;

int main(){
	int N; cin >> N; int pre = 0 , cnt = 0;
	for(int i = 1 ; i <= N ; ++i){
		int x; cin >> x;
		if(pre == x){++cnt; x = 10001;}
		pre = x;
	}
	cout << cnt; return 0;
}