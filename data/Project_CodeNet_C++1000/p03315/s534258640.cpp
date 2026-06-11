#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	char a[4];
	cin>>a;
	int p=0;
	int m=0;
	for(int i=0;i<4;i++){
		if(a[i]=='+'){
			p++;
		}
		else{
			m++;
		}
	}
	cout<<(-1*m)+p;
	return 0;
}