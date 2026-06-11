#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	char s[55];
	gets(s);
	int size = strlen(s) - 8;
	for(int i = 0; i ^ size; ++i)
		putc(s[i], stdout);
	return 0;
}