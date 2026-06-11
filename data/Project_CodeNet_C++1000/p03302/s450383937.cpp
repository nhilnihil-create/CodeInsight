#include<bits/stdc++.h>

using namespace std;

int x,y;

int main(){
	scanf("%d%d",&x,&y);
	if (x+y==15) puts("+");
	else if (x*y==15) puts("*"); else puts("x");
	
	return 0;
}
			