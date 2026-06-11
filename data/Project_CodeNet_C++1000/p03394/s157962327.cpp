#include <iostream>
#include <stdio.h>
using namespace std;

int N;

int id(int n){
	if(n==0) return 2;
	if(n==1) return 3;
	if(n==2) return 4;
	if(n==3) return 0;
}

int main(){
	scanf("%d",&N);
	if(N==3) printf("%d %d %d",2,5,63);
	else if(N==4) printf("%d %d %d %d",2,5,20,63);
	else if(N==5) printf("%d %d %d %d %d",2,5,20,30,63);
	else{
		bool A[30030] = {0};
		int count = 0,num = 2,c = 0,sum = 0;
		while(count<N){
			if(num%6==id(c)){
				A[num] = true;
				c++;
				c %= 4;
				count++;
				sum += num;
			}
			num++;
		}
		if(sum%6==2){
			A[8] = false;
			while(1){
				if(num%6==0){
					A[num] = true;
					break;
				}
				num++;
			}
		}else if(sum%6==3){
			A[9] = false;
			while(1){
				if(num%6==0){
					A[num] = true;
					break;
				}
				num++;
			}
		}else if(sum%6==5){
			A[9] = false;
			while(1){
				if(num%6==4){
					A[num] = true;
					break;
				}
				num++;
			}
		}
		int ans = 0;
		for(int i=2;i<=30000;i++){
			if(A[i]){
				ans++;
				cout << i << (ans!=N? " ":"\n");
			}
			if(ans==N) return 0;
		}
	}
}