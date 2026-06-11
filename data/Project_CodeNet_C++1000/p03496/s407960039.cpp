#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
int i,n,x,y,c,d;
x = -100010;
y = 100010;
cin >> n;
int a[n];
for(i=0;i<n;i++){
	cin >> a[i];
	if(x<a[i]){
		c = i+1;
	}
	x = max(x,a[i]);
	if(y>a[i]){
		d = i+1;
	}
	y = min(y,a[i]);
	}
cout << 2*n-1 << endl;
	if(x>-y){
		for(i=1;i<=n;i++){
			cout << c <<" "<< i << endl;
		}
		for(i=1;i<n;i++){
			cout << i <<" "<< i+1 << endl;
		}
	}else{
		for(i=1;i<=n;i++){
			cout << d <<" "<< i << endl;
		}
		for(i=n;i>1;i--){
			cout << i <<" "<< i-1 << endl;
		}
	}
}
