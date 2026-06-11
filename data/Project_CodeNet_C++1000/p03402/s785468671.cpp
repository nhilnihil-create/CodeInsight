#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
 
 
char x[105][105];
 
 
int main() {
	int a, b;
	cin >> a >> b;
	a--,b--;
	for(int i = 1;i <= 50; i++)
		for(int j = 1; j <= 100; j++)
			x[i][j] = '.';
	for(int i = 51; i <= 100; i++)
		for(int j = 1; j <= 100; j++)
			x[i][j] = '#';
	for(int i = 1;i <= 50 && b; i += 2)
		for(int j = 1; j <=100 && b; j += 2)
			x[i][j] = '#', b--;
	for(int i = 100; i > 50 && a; i-=2)
		for(int j = 1; j <= 100 && a;j += 2)
			x[i][j] = '.', a--;
	puts("100 100");
	for(int i = 1; i <= 100; i++, puts(""))
		for(int j = 1;j <= 100; j++)
			cout << x[i][j];
	return 0;
}
