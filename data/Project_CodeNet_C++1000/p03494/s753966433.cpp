#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n,c=0,p=0; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	while(1){ c=0;
        for(int i=0;i<n;i++){
            if(arr[i]%2==0)c++;
        }
        if(c==n){
            for(int i=0;i<n;i++){
                arr[i]=arr[i]/2;
            }p++;
        }
        else break;
	}
	cout<<p;
}
