#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
typedef string str;

#define endl "\n"

const int MOD = 1000000007;


int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    char a,b,t;
    char z = '>';
    char x = '<';
    char y = '=';
    
        scanf("%c %c",&a,&b);
        if(a > b){
        printf("%c\n",z);
        }
        else if(a < b){
            printf("%c\n",x);
        }
        else if(a == b){
            printf("%c\n",y);
        }
    
	return 0;
}
