// B - Maximum Difference
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	int amin = INT_MAX, amax = 0;
	for(int i=0; i<n; ++i){
		int a; cin>>a;
		amin = min(amin, a);
		amax = max(amax, a);
	}
	cout<< abs(amax - amin) <<endl;
}
