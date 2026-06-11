#include<iostream>
using namespace std;
int main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	
	int d = 2*c - a - b;
	int res = 1000000000;
	if (d >= 0) {
		
		cout << a*x + b*y <<endl;
		
	}
  	else  {
		
		for (int i=1; i<=max(x,y); i++) {
			
			res = min(res,max(x-i,0)*a+max(y-i,0)*b+2*i*c);
			
		}
	  
		
		cout << res << endl;
	}
    return 0;

}
