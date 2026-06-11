#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
bool w[30010];
inline int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int main() {
    int n,s=0;
    cin>>n;
    for(int i=1;n>1;i++)
	if(i%2==0||i%3==0)
	    w[i]=1,printf("%d ",i),s+=i,--n;
    for(int i=1;;i++)
	if(!w[i]&&(s+i)%6==0&&gcd(s,i)>1) return cout<<i,0;
    return 0;
}