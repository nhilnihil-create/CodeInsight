#include <bits/stdc++.h>
using namespace std;
long long a[200001];
int main(){
 int n;
 int op=0;
 long long sum=0;
 long long sum2=0;
 long long ap=0;
 cin >> n;
 for(int i=1;i<=n;i++){
	 cin >> a[i];
 }
 for(int i=1;i<=n;i++){
 	while(op<n&&(sum2^a[op+1])==sum+a[op+1]){
 		sum=sum+a[op+1];
 		sum2=sum2^a[op+1];
 		op++;
	 }
	 ap+=op-i+1;
	 sum-=a[i];
	 sum2=sum2^a[i];
 }
 cout <<ap << endl;
 return 0;
}