#include<bits/stdc++.h>
#define FI first
#define SE second
using namespace std;


long long n,k,pre,ans,preD[100005],preS[100005],a,b;
vector<long long> dis, single;
pair<long long,long long> arr[100005];

bool cmp (long long a, long long b){
	return a>b;
}

int main(){
	scanf("%lld%lld",&n,&k);
	for(int i =0;i<n;i++){
		scanf("%lld%lld",&a,&b);
		arr[i] = {a,-b};
	}
	sort(arr,arr+n);
	
	dis.push_back(0);
	single.push_back(0);

	pre = -1;
	for(int i =0;i<n;i++){
		if(arr[i].FI!=pre){
			// printf("push to dis %lld\n",-arr[i].SE);
			dis.push_back(-arr[i].SE);
		} else {
			single.push_back(-arr[i].SE);
			// printf("push to single %lld\n",-arr[i].SE);
		}
		pre = arr[i].FI;
	}

	sort(dis.begin()+1,dis.end(),cmp);
	sort(single.begin()+1,single.end(),cmp);

	for(int i= 1;i<dis.size();i++){
		preD[i] = preD[i-1]+dis[i];
	}
	for(int i= 1;i<single.size();i++){
		preS[i] = preS[i-1]+single[i];
	}
	for(long long i =0;i<=k;i++){
		if(i>=dis.size()||k-i>=single.size())continue;
		ans = max(ans, preD[i]+preS[k-i]+i*i);
	}
	printf("%lld\n",ans);
	return 0;
}
