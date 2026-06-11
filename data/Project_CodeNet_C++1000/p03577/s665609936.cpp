// Sooke bless me.
// LJC00118 bless me.
#include<bits/stdc++.h>

#define INF 2147483647
#define ll long long

int Inp(){
	char c = getchar();
	int Neg = 1;
	while(c < '0' || c > '9'){
		if(c == '-')
			Neg = -1;
		c = getchar();
	}
	int Sum = 0;
	while(c >= '0' && c <= '9'){
		Sum = ((Sum << 3) + (Sum << 1)) + c - '0';
		c = getchar();
	}
	return Neg * Sum;
}

int main(){
	char s[100];
	scanf("%s", s + 1);
	int l = strlen(s + 1);
	for(int i = 1; i <= l - 8; i++)
		putchar(s[i]);
}
