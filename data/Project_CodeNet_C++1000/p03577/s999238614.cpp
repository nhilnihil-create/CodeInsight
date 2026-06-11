#include<bits/stdc++.h>
using namespace std;

#define mian main
#define maxn 2000001
#define fo(i,a,b) for(register int (i)=(a);(i)<=(b);++(i))
#define rd read()
string s;

int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int mian() {
  cin>>s;
  fo(i,0,s.size()-9)
  {cout<<s[i];
  }
    return 0;

}

