#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int arr[10];
	
	for (int a=0;a<3;a++){
		scanf ("%d",&arr[a]);
	}
	
	int total;
	scanf ("%d",&total);
	
	sort(arr,arr+3);
	
	for (int a=1;a<=total;a++){
		arr[2]*=2;
	}
	
	
	printf ("%d\n",arr[0]+arr[1]+arr[2]);
	
	return 0;	
}
