#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int a,b;
	cin >> a >> b;
	int sum=a+b;
	int dec=a-b;
	int mul=a*b;
	
	int ans=max(sum,max(dec,mul));
	cout << ans << endl;
	return 0;
}
