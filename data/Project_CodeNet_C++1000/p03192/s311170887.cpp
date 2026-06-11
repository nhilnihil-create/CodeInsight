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

	char c;
	int a=0,i;
	
	for(i = 1;i <= 4;i++){
		c=getchar();
		if(c=='2'){
			a++;
		}
	}
	cout << a << endl;

	return 0;
}