#include<algorithm>
#include<clocale>
#include<cmath>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<istream>
#include<map>
#include<math.h>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
int n,a[100010],x,ans,mx=1000000000;
int main()
{
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	if (n==2){
		cout<<a[1]<<' '<<a[0]<<endl;
		return 0;
	}
	int x=(a[n-1]+1)/2;
	for (int i=n-1;i>0;i--)
		if (abs(x-a[i])<mx){
			mx=abs(x-a[i]);
			ans=a[i];
		}
	cout<<a[n-1]<<' '<<ans<<endl;
	return 0;
}