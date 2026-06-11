#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
	int n,a,b;
	cin>>n>>a>>b;
	if(n<=a+b){
		cout << min(a,b) << " " << a+b-n << endl;
	}else if(n>a+b){
		cout << min(a,b) << " " << "0" << endl;
	}
	return 0;
}
