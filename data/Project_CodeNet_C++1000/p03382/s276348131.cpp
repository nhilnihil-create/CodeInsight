# include <iostream>
# include <cstdio>
# include <algorithm>
using namespace std;
const int N = 2e5 + 12;
int n,a[N];
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
	int mx = -1,id = -1,mi = 0x3f3f3f3f,Id = -1;
	for(int i = 1;i <= n;i++)if(a[i] > mx)mx = a[i],id = i;
	for(int i = 1;i <= n;i++)if(i != id)
	{
	 if(mx & 1)
	 {
	 	if(a[i] > mx / 2 && a[i] - mx / 2 - 1 < mi)mi = a[i] - mx / 2 - 1,Id = i;
	 	else if(a[i] <= mx / 2 && mx / 2 - a[i] < mi)mi = mx / 2 - a[i],Id = i;
	 }
	 else if(abs(a[i] - mx / 2) < mi)mi = abs(a[i] - mx / 2),Id = i;
	}
	printf("%d %d\n",a[id],a[Id]);
}