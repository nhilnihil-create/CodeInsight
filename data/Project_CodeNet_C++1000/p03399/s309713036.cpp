#include<iostream>
#include<math.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int densha=min(a,b);
	int bus=min(c,d);
	int ans=densha+bus;
	cout << ans << endl;
	return 0;
}
