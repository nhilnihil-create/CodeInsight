#include<bits/stdc++.h>
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define umax(x,y) x=max(x,y)
#define umin(x,y) x=min(x,y)
#define ll long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define iiii pair<ii,ii>
#define sz(x) ((int) x.size())
#define orta ((bas+son)/2)
#define all(x) x.begin(),x.end()
#define pw(x) (1<<(x))
#define inf 1000000005
#define MOD 1000000007 
#define N 105
#define M 1000003
#define LOG 20
#define KOK 250
#define EPS 0.0000001
using namespace std;

bitset<4000005> ok;

int main() {

	int n,sum=0;

	ok[0]=1;

	scanf("%d",&n);

	for(int i=1;i<=n;i++) {

		int x;

		scanf("%d",&x);

		sum+=x;

		ok=ok|(ok<<x);

	}

	for(int i=(sum+1)/2;;i++) {

		if(ok[i]) {

			printf("%d",i);

			return 0;

		}

	}

}