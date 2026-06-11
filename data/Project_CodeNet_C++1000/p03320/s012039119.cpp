#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<ll> dic;
inline int S(ll x){
	int sum=0;
	while(x){
		sum+=x%10;
		x/=10;
	}
	return sum;
}
int main(){
	int K;
	scanf("%d",&K);
	dic.push_back(999999999999999ll);
	int idx=0;
	while(idx<(int)dic.size()){
		ll cur=dic[idx++];
		bool found=false;
		for(ll i=1;i<=1000000000000000ll && !found;i*=10){
			for(int digit=1;digit<=9 && !found;digit++){
				ll tmp=cur-digit*i;
				if(tmp>0 && tmp*S(cur)<=cur*S(tmp)){
					dic.push_back(tmp);
					found=true;
				}
			}
		}
	}
	sort(dic.begin(),dic.end());
	for(int i=0;i<K;i++)
		printf("%lld\n",dic[i]);
	return 0;
}