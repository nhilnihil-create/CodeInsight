#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B;
	cin >> A >> B;
	char ans[100][100];
	for(int i=0;i<100;i++)for(int j=0;j<100;j++){
		if(i<50)ans[i][j]='#';
		else ans[i][j]='.';
	}
	
	int a=1,b=1;
	for(int i=0;i<50;i+=2)for(int j=0;j<100;j+=2){
		if(a==A)break;
		ans[i][j]='.';
		a++;
	}
	for(int i=0;i<50;i+=2)for(int j=0;j<100;j+=2){
		if(b==B)break;
		ans[99-i][99-j]='#';
		b++;
	}
	
	cout << "100 100" << endl;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			cout << ans[i][j];
		}
		cout << endl;
	}
	
	return 0;
}