#include<stdio.h>
int position(int a[], int start, int end)
{
	int pindex, pvalue=a[end], temp, i;
	for(i=pindex=start; i<end; i++)
	{
		if(a[i]<pvalue)
		{
			temp = a[i];
			a[i] = a[pindex];
			a[pindex] = temp;
			pindex++;
		}
	}
	temp = a[i];
	a[i] = a[pindex];
	a[pindex] = temp;
	return pindex;
}
void quicksort(int a[], int start, int end)
{
	if(start>=end) return;
	int index = position(a, start, end);
	quicksort(a, start, index-1);
	quicksort(a, index+1, end);
	return;
}
int main()
{
	int n, a[101], x, i;
	while(~scanf("%d %d", &n, &x))
	{
		for(i=0; i<n; i++)
			scanf("%d", a+i);
		quicksort(a, 0, n-1);
		for(i=0; i<n;i++)
		{
			if(a[i]<=x) x-=a[i];
			else break;
		}
		if(i==n && x != 0) printf("%d\n", --i);
		else printf("%d\n", i);
	}
	return 0;
}