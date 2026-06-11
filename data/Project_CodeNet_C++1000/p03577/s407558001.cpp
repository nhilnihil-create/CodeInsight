#include <bits/stdc++.h>
using namespace std;

char str[100];

int main (){
	int len;
	scanf("%s", str);
	len = strlen(str);
	str[len - 8] = 0;
	puts(str);
	return 0;
}
