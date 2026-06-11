#include<bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(register int (i)=(a);(i)<=(b);++(i))
#define rd read()
#define maxn 200001
#define gc getchar()
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define pb push_back
#define db double
#define pu puts(" ")
const int p=998244353;
int read() {
	int x=0,f=1;
	char ch=gc;
	while(!isdigit(ch)) {
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(isdigit(ch))x=x*10+ch-48,ch=gc;
	return x*f;
}
void print(int x) {
	if(x>9)print(x/10);
	putchar(x%10+48);
}

int main() {
    int n=rd,a=rd,b=rd;
    printf("%d %d\n",min(a,b),max(a+b-n,0));
	return 0;
}