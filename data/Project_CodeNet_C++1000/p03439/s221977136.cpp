#include <bits/stdc++.h>
using namespace std;
#define ALL(A) (A).begin(),(A).end()

int check(int x){
	string s;
	cout << x << endl << flush;
	cin >> s;
	if(s == "Vacant")return 0;
	else if(s == "Male")return 1;
	else return 2;
}

int main(void){
	int N;cin >> N;
	int left = 0;
	int right = N;
	int x = check(0);
	if(x == 0)return 0;
	else if(x == 1){
		while(true){
			int mid = (left+right)/2;
			int next = check(mid);
			if(mid%2==0){
				if(next==0)return 0;
				else if(next==1)left = mid;
				else right = mid;
			}else{
				if(next==0)return 0;
				else if(next==2)left = mid;
				else right = mid;
			}
		}
	}else{
		while(true){
			int mid = (left+right)/2;
			int next = check(mid);
			if(mid%2==0){
				if(next==0)return 0;
				else if(next==2)left = mid;
				else right = mid;
			}else{
				if(next==0)return 0;
				else if(next==1)left = mid;
				else right = mid;
			}
		}
	}
}