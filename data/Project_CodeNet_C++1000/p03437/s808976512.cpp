#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
	int x,y;
	cin >> x >> y;
	if(x%y==0){
		cout << "-1" << endl;
		return 0;
	}else{
		int a=2;
		while(1){
			if(a*x % y!= 0){
				cout << a*x << endl;
				return 0;
			}else{
				a++;
			}	
		}
	}
	return 0;
}
