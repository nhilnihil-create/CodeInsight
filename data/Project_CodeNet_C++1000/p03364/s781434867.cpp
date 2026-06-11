#include<bits/stdc++.h>
using namespace std;

char s[310][310];
char t[310][310];
int main(void){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>s[i][j];
	int a=0;
	for(int i=0;i<n;i++){
		//a=0,b=i
		for(int j=0;j<n;j++)for(int k=0;k<n;k++){
			t[j][k] = s[j][(k+i)%n];
		}
		bool check = true;
		for(int j=0;j<n;j++)for(int k=0;k<n;k++){
			if(!(t[j][k] == t[k][j]))check = false;
		}
		if(check)a++;
	}
	cout << n*a << endl;
	return 0;
}