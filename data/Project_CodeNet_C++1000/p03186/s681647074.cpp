#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
using namespace std;
int A,B,C;
int main()
{
	return scanf("%d%d%d",&A,&B,&C),printf("%d\n",B+min(C,A+B+1)),0;
}