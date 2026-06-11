#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	char s;
	cin>>s;
	if(s=='A'){
		cout<<"T";
	}
	else if(s=='T'){
		cout<<"A";
	}
	else if(s=='C'){
		cout<<"G";
	}
	else{
		cout<<"C";
	}
	return 0;
}