#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long int ll;

bool comp(ll x, ll y){
	ll x1=x, y1=y;
	ll d1=0, d2=0;
	while(x1>0){
		d1+=(x1%10);
		x1/=10;
	}
	while(y1>0){
		d2+=(y1%10);
		y1/=10;		
	}
	if(x*d2!=y*d1){
		return x*d2<y*d1;
	}else{
		return x<y;
	}
}

int main()
{
	int k;
	scanf("%d", &k);
	vector<ll> v;
	ll p10=1;
	set<ll> st;
	for(ll d=1; d<=13; d++){
		for(ll i=1; i<1000; i++){
          if((i+1)*p10-1<=1e15){
			st.insert((i+1)*p10-1);
          }
		}
		p10*=10;
	}
	for(auto itr=st.begin(); itr!=st.end(); itr++){
		v.push_back(*itr);
	}
	bool e[200000]={};
  	ll m=v.back();
	for(int i=v.size()-2; i>=0; i--){
		if(!comp(v[i], m)){
          e[i]=1;
        }else{
          m=v[i];
        }
	}
	int t=0, i0=0;
	while(t<k){
		if(e[i0]==1){
			i0++;
			continue;
		}else{
			printf("%lld\n", v[i0]);
          i0++;
          t++;
        }
    }
	return 0;
}
