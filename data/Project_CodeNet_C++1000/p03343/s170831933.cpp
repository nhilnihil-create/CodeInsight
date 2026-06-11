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
int p[2100];

int main(){
	int a,b,c;scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<a;i++)scanf("%d",p+i);
	int ret=mod;
	for(int i=0;i<a;i++){
		vector<int>v;
		int kj=p[i];
		int cur=0;
		for(int j=0;j<a;j++){
			if(p[j]<kj){
				vector<int>tmp;
				for(int k=1;k<=cur;k++){
					tmp.push_back(p[j-k]);
				}
				std::sort(tmp.begin(),tmp.end());
				for(int k=0;k+b<=tmp.size();k++){
					v.push_back(tmp[k]);
				}
				cur=0;
			}else cur++;
		}
		vector<int>tmp;
		for(int k=1;k<=cur;k++){
			tmp.push_back(p[a-k]);
		}
		std::sort(tmp.begin(),tmp.end());
		for(int k=0;k+b<=tmp.size();k++){
			v.push_back(tmp[k]);
		}
		std::sort(v.begin(),v.end());
		if(v.size()>=c){
			ret=min(ret,v[c-1]-kj);
		}
	}
	printf("%d\n",ret);
}
