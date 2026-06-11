#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> an(5);
	int k;
	for(int i=0; i<5; i++) cin >> an[i];
	cin >> k;
	cout << (an[4]-an[0]<=k?"Yay!":":(") << endl;
	return 0;
}