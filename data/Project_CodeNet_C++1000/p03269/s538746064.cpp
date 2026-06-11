#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int MAX_N = 1000001;
int n;

vector<int> v;

int main(void) {
	scanf("%d", &n);n--;
	if(n==1) {
		printf("2 2\n1 2 0\n1 2 1");
		return 0;
	}
	int t = n;
	int dig=0;
	int cnt=0;
	while(t) {
		if(t&1) {
			cnt++;
			v.push_back(dig);
		}
		dig++;
		t>>=1;
	}
	printf("%d %d\n", dig, 2*dig+cnt-2);
	for(int i=1; i<dig; i++) printf("%d %d %d\n%d %d %d\n", i, i+1, 0, i, i+1, 1<<(i-1));
	int cur=0;
	for(int i=sz(v)-1; i>0; i--) {
		cur+=(1<<v[i]);
		printf("%d %d %d\n", v[i-1]+1, dig, cur);
	}
	printf("%d %d %d\n", 1, dig, n);
}
