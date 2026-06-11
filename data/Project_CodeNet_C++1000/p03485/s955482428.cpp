#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); 
	int a, b; cin >> a >> b;
	double x =((double)a + b) / 2;
	cout <<ceil(x) << endl;
	return 0;
}


