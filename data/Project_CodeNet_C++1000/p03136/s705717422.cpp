#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define ge getchar
#define pun putchar('\n')
#define pu putchar
#define pus putchar('Y'),putchar('e'),putchar('s')
#define puo putchar('N'),putchar('o')
char c;
int n,s,a,d;
ll g[50];
int sri(){c=ge();int x=0;while(c<'0')c=ge();while(c>='0')x=(x<<3)+(x<<1)+c-'0',c=ge();return x;}
int main(){
	n=sri();
	while(n--){
		a=sri();if(a>d)d=a;s+=a;
	}
	if(s>d+d)pus;else puo;
    return 0;
}