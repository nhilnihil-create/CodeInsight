#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
 
using namespace std;
 
int main(){
	vector<int> a(3,0);
	vector<int> b(3,0);
	vector<int> c(4,0);
	
	for(int i=0;i<3;i++){
		cin >> a[i] >> b[i];
		if(a[i]==b[i]){
			cout << "NO" << endl;
			return 0;
		}
		c[a[i]-1]++;
		c[b[i]-1]++;
	}
	
	for(int i=0;i<4;i++){
		if(c[i]>=3 || c[i] <=0){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	
	return 0;
}