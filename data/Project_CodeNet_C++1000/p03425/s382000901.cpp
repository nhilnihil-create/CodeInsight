#include<cstdio>

int main(){
	unsigned N;
	scanf("%u\n", &N);
	unsigned long long a=0, b=0, c=0, d=0, e=0;
	for (unsigned i = 0; i < N; ++i)	{
		char tmp[15];
		scanf("%s", tmp);
		if(tmp[0] == 'M') a++;
		if(tmp[0] == 'A') b++;
		if(tmp[0] == 'R') c++;
		if(tmp[0] == 'C') d++;
		if(tmp[0] == 'H') e++;
	}
	printf("%llu\n", a*(b*(c+d+e)+c*(d+e)+d*e)+b*(c*(d+e)+d*e)+c*d*e);
	return 0;
}