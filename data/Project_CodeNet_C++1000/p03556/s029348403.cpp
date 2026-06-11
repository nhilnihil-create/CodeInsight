#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

bool heiho(long x){
	long a=(int)sqrt(x);
	if(a*a==x){
		return true;
	}else{
		return false;
	}
}

int main(){
	long n;
	cin >> n;
	for(long i=n;i>0;i--){
		if(heiho(i)==true){
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
