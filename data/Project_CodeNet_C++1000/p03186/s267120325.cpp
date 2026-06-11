#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int Max = 1000000;
int main(){
	ll A, B, C;
	cin >> A >> B >> C;

	if(C<=A+B+1){
		cout << B+ C <<endl;
	}else{
		ll ans = A+B+1;
		ans += B;
		cout << ans <<endl;
	}
  	
   
  	return 0;
}

