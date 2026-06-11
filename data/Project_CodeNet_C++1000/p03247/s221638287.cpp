#include <bits/stdc++.h>
#define LL long long
#define mp make_pair
#define pb push_back
#define VI vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
int n, X[1010], Y[1010];
int movx[] = {1,-1,0,0};
int movy[] = {0,0,1,-1};
char mov[] = {'L', 'R', 'D', 'U'};
string solve(LL x, LL y, LL pw){
	string ans = "";
	for(LL i = pw-1; i >= 0; i--){
		for(int j = 0; j < 4; j++){
			LL nx = x + movx[j]*(1LL<<i);
			LL ny = y + movy[j]*(1LL<<i);
			if(llabs(nx) + llabs(ny) <= ((1LL<<i)-1)){
				x = nx;
				y = ny;
				ans += mov[j];
				break;
			}
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main(){
	scanf("%d", &n);
	int p = -1;
	for(int i = 0; i < n; i++){
		scanf("%d %d", &X[i], &Y[i]);
		if(p == -1) p = (abs(X[i]) + abs(Y[i]))%2;
		else if(abs(X[i] + abs(Y[i]))%2 != p){
			printf("-1\n");
			return 0;
		}
	}
	if(!p){
		for(int i = 0; i <n; i++) X[i]--;
	}
	int mx = 0;
	for(int i = 0; i < n; i++){
		mx = max(mx, abs(X[i]) + abs(Y[i]));
	}
	LL pw = 1;
	for(; (1LL<<pw)-1 < mx; pw++);
	printf("%d\n", pw + !p);
	for(LL i = 0; i < pw; i++){
		if(i == 0 && !p) printf("1 ");
		printf("%lld ", (1LL<<i));
	}
	printf("\n");
	for(int i = 0; i < n; i++) mx = max(mx, abs(X[i]) + abs(Y[i]));
	for(int i = 0; i < n; i++){
		string x = solve(X[i], Y[i], pw);
		printf("%s%s\n", !p ? "R":"", x.c_str());
	}
	return 0;
}