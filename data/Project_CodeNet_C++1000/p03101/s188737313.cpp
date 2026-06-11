#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

int seiyaku_check(long i,long Min,long Max){
	if(Min <= i && i <= Max){
		return 1;
	}else{
		exit(1);
		//return 0;
	}
}

int main(){
	
	int H,W;
	int h,w;
	int K,k;
	
	cin >> H >> W;
	seiyaku_check(H,1,20);
	seiyaku_check(W,1,20);
	
	cin >> h >> w;
	seiyaku_check(h,1,H);
	seiyaku_check(w,1,W);

	k=H*W-(H*w+W*h)+h*w;
	
	cout << k << endl;
	
return 0;
}
