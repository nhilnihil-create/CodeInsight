#include<bits/stdc++.h>
using namespace std;
void qsort(int l,int r,int a[])
{
    int mid=a[(l+r)/2];
    int i=l,j=r;
    do{
        while(a[i]<mid) i++;
        while(a[j]>mid) j--;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);
    if(l<j) qsort(l,j,a);
    if(i<r) qsort(i,r,a);
}
int main(){
	int a[1001];
	for(int i=1;i<=3;++i){
		cin>>a[i];
	}
	qsort(1,3,a);
	cout<<a[3]*10+a[1]+a[2];
}