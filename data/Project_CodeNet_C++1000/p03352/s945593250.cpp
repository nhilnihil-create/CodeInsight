#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

bool f(int a){
	for(int i = 1;i <= a;i++){
		for(int j = 2;j <= 10;j++){
			if(pow(i,j) == a){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int x;
	cin >> x;
	while(1){
		if(f(x)){
			cout << x << endl;
            return 0;
		}
		x--;
	}
}