#include <bits/stdc++.h>
#define db(x) cerr<<#x<<" = "<<x<<'\n';
using namespace std;

struct Edge {
	int u,v,w;
};

int L;
vector<Edge> edges;

void addEdge(int u,int v,int w) {
	edges.push_back({u,v,w});
}

void print(int n) {
	cout<<n<<' '<<edges.size()<<'\n';
	for(Edge edge:edges)
		cout<<edge.u<<' '<<edge.v<<' '<<edge.w<<'\n';
}

int main() {
	//freopen("input","r",stdin);
	//freopen("output","w",stdout);
	cin>>L;
	int k=log2(L),mul=1;
	for(int i=1;i<=k;i++) {
		addEdge(i,i+1,mul);
		addEdge(i,i+1,0);
		mul*=2;
	}
	int rem=L-(1<<k);
	for(int i=k;i>=1;i--)
		if(rem>=(1<<(i-1))) {
			rem-=(1<<(i-1));
			addEdge(i,k+1,mul);
			mul+=(1<<(i-1));
		}
	print(k+1);
}

