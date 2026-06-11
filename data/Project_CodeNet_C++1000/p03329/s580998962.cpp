#include<bits/stdc++.h>
using namespace std;
int n,opt[100005];
int c[20] = {1,6,36,216,1296,7776,46656,9,81,729,6561,59049};
int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		opt[i] = i;
		for(int j = 0;j < 12;j++)
			if (i >= c[j]) opt[i] = min(opt[i],opt[i - c[j]] + 1);		
	}
	cout << opt[n] << endl;
	return 0;		
}