#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
struct node{
	int p, y, id;	
}a[N];

bool cmp1(node c1, node c2) {
	if(c1.p == c2.p) return c1.y < c2.y;
	else return c1.p < c2.p;	
}
bool cmp2(node c1, node c2) {
	return c1.id < c2.id;	
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=0;i < m; i++) {
		scanf("%d %d", &a[i].p, &a[i].y);
		a[i].id = i + 1;
	}
	sort(a, a + m, cmp1);
	int cnt = 1;
	for(int i = 0; i < m; i++) {
		if( i >= 1 && a[i].p == a[i - 1].p) {
			cnt++;
		} else {
			cnt = 1;
		}
		a[i].y = cnt;
	}
		sort(a, a + m, cmp2);
	for (int i = 0; i < m; i++) {
		printf("%06d%06d\n", a[i].p, a[i].y);
	}
	
	return 0;
}