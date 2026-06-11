#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
using namespace std;

int main(){
	long long x,y;
	cin >> x >> y;
	long long cnt=1;
	while(1){
		if(x>y){
			cnt--;
			break;
		}
		if(x==y){
			break;
		}
		x=x*2;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}
