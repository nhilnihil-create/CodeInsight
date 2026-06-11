#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
long long p10[17];
int S(long long a){
	int ret=0;
	while(a){
		ret+=a%10;
		a/=10;
	}
	return ret;
}
int main(){
	long long a;
	scanf("%lld",&a);
	vector<long long>hb;
	p10[0]=1;
	for(int i=1;i<17;i++)p10[i]=p10[i-1]*10;
	for(int i=1;i<=15;i++){
		for(int j=0;j<9;j++){
			for(int k=0;k<10;k++){
				for(int l=0;l<10;l++){
					if(k&&i==1)continue;
					if(l&&i<3)continue;
					if(i>2)hb.push_back(p10[i]-1-j*p10[i-1]-k*p10[i-2]-l*p10[i-3]);
					else if(i>1)hb.push_back(p10[i]-1-j*p10[i-1]-k*p10[i-2]);
					else hb.push_back(p10[i]-1-j*p10[i-1]);
				}
			}
		}
	}
	std::sort(hb.begin(),hb.end());
	int cnt=0;
	for(int i=0;i<hb.size();i++){
		bool ok=true;
		for(int j=i+1;j<hb.size();j++){
			if(hb[i]*S(hb[j])>hb[j]*S(hb[i])){ok=false;break;}
		}
		if(ok){
			printf("%lld\n",hb[i]);
			cnt++;
			if(cnt==a)break;
		}
	}
}
