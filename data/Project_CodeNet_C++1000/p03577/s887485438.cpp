#include <bits/stdc++.h>

using namespace std;

int main(){
	char s[10086];
	scanf("%s", s);
	for (int i = 0; i < strlen(s) - 8; i++)
		printf("%c", s[i]);
	puts("");
    return 0;
}