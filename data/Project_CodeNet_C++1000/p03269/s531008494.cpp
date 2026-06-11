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
#define inf 1000000000
#define MOD 1000000007 
#define N 100005
#define M 1000000
#define LOG 20
#define KOK 300
#define EPS 0.0000001
using namespace std;

struct edge {
	
	int a,b,c;

};

vector<edge> e;
int l;
int tut[22];

int main() {

	scanf("%d",&l);

	int cur=0;

	for(int i=19;i>=0;i--) {

		if(l&(1<<i)) {

			if(!cur) {

				int now=1;

				for(int j=i-1;j>=0;j--,now++) {

					e.pb({now,now+1,1<<j});
					e.pb({now,now+1,0});

					tut[j]=now;

				}

			}
			else {

				e.pb({1,tut[i]+1,cur});

			}

			cur+=(1<<i);

		}
	
	}

	printf("%d %d\n",tut[0]+1,sz(e));

	for(auto x:e) {

		printf("%d %d %d\n",x.a,x.b,x.c);

	}

}	