#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;

struct node{
	int u,v,w;
};
vector <node> edge;

int main(){
	int l;
	scanf("%d",&l);
	int n = 0;
	for (;(1 << n) <= l;n++);
	for (int i = 1; i < n; i++) { 
		edge.pb(node{i , i + 1 , (1 << (i - 1))});
		edge.pb(node{i , i + 1 , 0});
	}
	int now = (1 << (n - 1));
	for (int i = n - 1; i >= 1; i--) {
		if (now + (1 << (i - 1)) - 1 < l) {
			edge.pb(node{i , n , now});
			now += (1 << (i - 1));
		}
	}
	printf("%d %d\n" , n , edge.size());
	for (auto ans : edge)
		printf("%d %d %d\n" , ans.u , ans.v , ans.w);
} 
