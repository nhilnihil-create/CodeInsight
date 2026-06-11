#include<iostream>
using namespace std;

int main(){
	int a, b, c, x;
	cin >> a; // 500円玉
	cin >> b; // 100円玉
	cin >> c; // 50円玉
	cin >> x;

	int total,res;
	res=0;
	
	for(int i=0;i<a+1;i++) {
		for(int j=0;j<b+1;j++){
			for(int k=0;k<c+1;k++){
				total = 500*i+100*j+50*k;
				if(total==x)res++;
			}
		}
	}
	cout << res << endl;
}