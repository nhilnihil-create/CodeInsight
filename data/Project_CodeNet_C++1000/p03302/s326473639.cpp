# include <iostream>
# include <cstdio>
# include <cmath>
# include <cstring>
# include <string>
# include <cstdlib>
# include <algorithm>
# include <stack>
# include <queue>
# include <vector>
# define maxx (103)
# define Pi (3.14159265358979)
# define inf (2147483647)
using namespace std;
int read() {
	int x=0,f=1;
	char ch;
	while(ch<'0'||ch>'9')  {
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+ch-'0';
		ch=getchar();
	}
	return f*x;
}
int main() {

	int a,b;
	a=read();
	b=read();
	
	if(a+b==15){
		cout << "+";
	}else if(a*b==15){
		cout << "*";
	}else{
		cout << "x";
	}

	return 0;
}