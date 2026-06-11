#include<iostream>
using namespace std;
int main(){
  	int a,b,c,d,x,y;
  	cin >> a >> b >> c >> d;
  	x=a;
  	if(a>b)
      	x=b;
  	if(c<d)
      	x+=c;
  	else
      	x+=d;
  	cout << x << endl;
	return 0;
}