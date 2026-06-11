#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
	int n;
	cin >> n;
	int x=n,cnt=0;
	while(x){
		if(x%10==2){
			cnt++;
		}
		x=x/10;
	}
	cout << cnt << endl;
	return 0;
}
