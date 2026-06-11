#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,x;
	cin >> a >> b >> c >> x;
	
	int cnt = 0;
	for(int i = 0;i<=a;i++){
		for(int j = 0;j<=b;j++){
			for(int k= 0;k<=c;k++){
				int as = i*500;
				int bs = j*100;
				int cs = k*50;
				if(as+bs+cs == x) cnt++;
			}
		}
	}
	
	cout << cnt << endl;
}