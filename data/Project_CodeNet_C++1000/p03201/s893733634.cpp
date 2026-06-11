#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
#include<math.h>
#include <iomanip>
using namespace std;
int arr[200000];
int arr1[200000], arr2[200000];
int ind=0;
int n;
int culc(int cur){
	int fr=0;
	int ls=ind;
	int mid;
	while(ls>=fr){
		mid=(fr+ls)/2;
		if (arr1[mid]>cur)ls=mid-1; else if(arr1[mid]<cur)fr=mid+1; else return mid;
	}
	return -1;
}

int main(){
	
	long long arr3[31];
	arr3[0]=1;
	for(int i=1;i<31;i++)arr3[i]=arr3[i-1]*2;
	
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++)arr2[i]=0;
	arr1[0]=arr[0];
	arr2[0]=1;
	
	for(int i=1;i<n;i++){
		if(arr[i]!=arr[i-1])arr1[++ind]=arr[i];
		arr2[ind]++;
	}
	for(int i=ind;i>=0;i--){
		long long cur;
		for(int j=30;j>=0;j--){
			if(arr1[i]>=arr3[j]){
				cur=arr3[j+1];
				//cout<<arr1[i]<<" "<<cur<<" "<<arr3[j]<<" "<<ind<<endl;
				break;
			}
		}
		if(cur==arr1[i]*2){
			ans+=arr2[i]/2;
			continue;
		}
	//cout<<arr2[i]<<" "<<culc(cur-arr1[i])<<" "<<arr2[culc(cur-arr1[i])]<<endl;
		int ot=culc(cur-arr1[i]);
		if(ot==-1)continue;
		int cut=min(arr2[i],arr2[ot]);
		ans+=cut;
		//cout<<arr1[i]<<" "<<cut<<endl;
		arr2[ot]-=cut;
	}
	cout<<ans<<endl;
		
	return 0;
}