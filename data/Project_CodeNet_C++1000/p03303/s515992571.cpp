#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define pb 			push_back
#define mp 			make_pair
#define max(a,b) 	(a>b?a:b)
#define min(a,b) 	(a<b?a:b)
const int sz = 1e5 + 5;

int cnt[105], cnt2[105];

int main(){
	
	//ios_base::sync_with_stdio(false);

	char a[sz];
	scanf("%s", a);
	int w;
	scanf("%d", &w);
	int l = strlen(a);
	for(int i = 0; i < l; i+=w){
		printf("%c", a[i]);
	}
	puts("");
	
	return 0;
}