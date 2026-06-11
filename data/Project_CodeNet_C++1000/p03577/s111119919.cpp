#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char c[51];
	cin>>c;
	int n=strlen(c);
	int p=n;
	for(int i=0;i<n;i++){
		if(p<=8){
			break;
		}
		cout<<c[i];
		p--;
	}
	cout<<"\n";
	return 0;
}