#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define mod 1000000007

int main(void) {
	// your code goes here
	int a,b,g[101][101],i,j;
	cin >> a >> b;
	cout << "100 100" << endl;
	for(i=1;i<=50;i++){
		for(j=1;j<=100;j++) g[i][j]=0;
	}
	for(i=51;i<=100;i++){
		for(j=1;j<=100;j++) g[i][j]=1;
	}
	
	for(i=1;i<=a-1;i++) g[2*((i-1-(i-1)%50)/50)+1][2*((i-1)%50)+1]=1;
	for(i=1;i<=b-1;i++) g[101-(2*((i-1-(i-1)%50)/50)+1)][101-(2*((i-1)%50)+1)]=0;
	
	for(i=1;i<=100;i++){
		for(j=1;j<=100;j++){
			if(g[i][j]==1) cout << ".";
			else cout << "#";
		}
		cout << endl;
	}
	return 0;
}
