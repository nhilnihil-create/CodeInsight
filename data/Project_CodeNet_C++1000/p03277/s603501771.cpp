#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <bitset>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <cassert>
using namespace std;
int dx[5]={1,0,-1,0,0},dy[5]={0,1,0,-1,0};
long long gcd(long long a,long long b){if(a%b==0){return b;}else return gcd(b,a%b);}
long long lcm(long long a,long long b){if(a==0){return b;} return a/gcd(a,b)*b;}
#define INF 2000000000
#define MOD 1000000007
#define sym cout<<"---------"<<endl;
#define ll long long
#define mk make_pair
#define en endl
#define RE return 0
#define int ll
#define P pair<int,int>

#define MAX 200005

int dat[MAX];

struct BIT{
	int bit[MAX];
	void init(){
		memset(bit, 0, sizeof(bit));
	}
	void add(int i,int x){
		i++;
		while(i<MAX){
			bit[i]+=x;
			i+=i&-i;
		}
	}
	int get(int i){
		i++;
		int ret=0;
		while(i>0){
			ret+=bit[i];
			i-=i&-i;
		}
		return ret;
	}
};

BIT bit;

signed main(){
	int num; cin>>num;
	for(int i=0; i<num; i++) cin>>dat[i];
	
	int fir=0,last=11000000000;
	for(;;){
		if(fir==last) break;
		int mid=(fir+last)/2;
		int cnt=0,now=0;
		bit.init();
		bit.add(MAX/2, 1);
		for(int i=0; i<num; i++){
			now+=(dat[i]<=mid)?1:-1;
			cnt+=bit.get(MAX/2+now-1);
			bit.add(MAX/2+now, 1);
		}
		if(cnt<num*(num+1)/4+1) fir=mid+1;
		else last=mid;
	}
	cout<<fir<<en;
}


