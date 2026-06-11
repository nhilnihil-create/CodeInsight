#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n,k,res=0; cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
        while(i<n-1 && arr[i]==arr[i+1])++i; res++;
	}
	if(res<=k)cout<<0;
	else{ int M=200005,m=arr[n-1]; long c=0;
        int a[M]={0};
        for(int i=0;i<n;i++){
            a[arr[i]]++;
        }
        sort(a,a+m+1);
        for(int i=0;i<=m;i++){
            if(a[i]>0){
            c=c+a[i];
            res--;
            if(res<=k)break;}
        }
        cout<<c;
	}
}
