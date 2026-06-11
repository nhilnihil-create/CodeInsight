#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;


int main(){
	long a,b;
	cin >> a >> b;
	
	long p=max(a,b)-min(a,b);
	long sum=0;
	for(long i=1;i<=p;i++){
		sum+=i;
	}
	cout << sum-max(a,b) << endl;
}

