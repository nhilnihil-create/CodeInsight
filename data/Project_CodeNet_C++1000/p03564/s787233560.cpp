#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n,k;
	cin >> n >> k;
	int num = 1;
	for(int i = 0;i < n;i++){
		if(num*2 > num+k){
			num += k;
		}else{
			num*=2;
		}
	}
	cout << num << endl;
}