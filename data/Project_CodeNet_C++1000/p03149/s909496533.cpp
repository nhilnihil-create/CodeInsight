#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>

using namespace std;

int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a+b+c+d==1+9+7+4 && a*b*c*d==1*9*7*4){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}
