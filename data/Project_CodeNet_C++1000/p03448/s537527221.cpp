#include<iostream>
using namespace std;


int main(){
	int A,B,C,X;
	int cnt=0;
	cin >> A;
	cin >> B;
	cin >> C;
	cin >> X;

	for(int x=0;x<=A;x++){
		for(int y=0;y<=B;y++){
			for(int z=0;z<=C;z++){
				cnt+=(500*x+100*y+50*z==X);
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
