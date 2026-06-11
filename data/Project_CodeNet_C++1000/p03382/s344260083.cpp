#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<climits>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>
#include<iomanip>
#include<sstream>

using namespace std;
#define ll long long
inline ll read() {
    char ch = getchar(); ll x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
int a[5000000];
int main(){
	int n=read();
	for (int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int now=a[1];
	for (int i=1;i<n;i++)
	if (abs(now*2-a[n])>abs(a[i]*2-a[n]))
		now=a[i];
	cout<<a[n]<<' '<<now;
}
