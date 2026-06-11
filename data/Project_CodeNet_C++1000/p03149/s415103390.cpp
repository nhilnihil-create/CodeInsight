#include<bits/stdc++.h>
using namespace std;
int main(){
	int N1,N2,N3,N4;
	vector<int>ivec(10,'0');
	cin >> N1 >> N2 >> N3 >> N4;
	ivec[N1]=1;
	ivec[N2]=1;
	ivec[N3]=1;
	ivec[N4]=1;
	if(ivec[1]==1 && ivec[4]==1 && ivec[7]==1 && ivec[9]==1){cout << "YES";
	}
	 else {
	cout << "NO";}
	return 0;
}