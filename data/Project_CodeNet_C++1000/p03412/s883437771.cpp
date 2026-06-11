#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
#include<time.h>
using namespace std;

int n;
long long arr[400000];
long long brr[400000];
int ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld",arr+i);
	}
	for(int i=0;i<n;i++){
		scanf("%lld",brr+i);
	}
	for(int i=0;i<30;i++){
		int mod=(1<<(i+1))-1;
		vector<int> a;
		vector<int> b;
		//각 수를 mod로 나눈 나머지
		for(int j=0;j<n;j++){
			a.push_back(arr[j] & mod);
		}
		for(int j=0;j<n;j++){
			b.push_back(brr[j] & mod);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		long long ret=0;
		for(int j=0;j<n;j++){
			//a[j] + b[k] 가 (1<<i)이상 (1<<(i+1)) 미만
			//a[j] + b[k] 가 3*(1<<i) 이상 (1<<(i+2))미만의 수의 합을 구하자
			int x=lower_bound(b.begin(),b.end(),(1<<(i+1))-a[j])-lower_bound(b.begin(),b.end(),(1<<i)-a[j]);
			int y=lower_bound(b.begin(),b.end(),(1<<(i+2))-a[j])-lower_bound(b.begin(),b.end(),3*(1<<i)-a[j]);
			ret+=(x+y);
		}
		if(ret%2==1) ans+=(1<<i);
	}
	cout<<ans;
	return 0;
}