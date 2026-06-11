#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef pair<int , int> ii;
typedef pair<ii , int> iii;
const ll mod = 1e9;
int n , half;
bool visited[3050][3050];
double a[3050] , memo[3050][3050];
double dp(int x , int tails){
	if(x > n + 1)return 0;
	if(x == n + 1){
		if(tails < half)return 1;
		else return 0;
	}
	if(visited[x][tails])return memo[x][tails];
	visited[x][tails] = true;
	memo[x][tails] = (a[x]*dp(x + 1 , tails)) + ((1 - a[x])*dp(x + 1 , tails + 1));
	return memo[x][tails];
}
void input(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> a[i];
	}
}

void solve(){
	half = n/2;
	if(n % 2 == 1)half++;
	memset(visited , false , sizeof(visited));
	memset(memo , -1 , sizeof(memo));
	printf("%.10lf\n" , dp(1 , 0));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	input();
	solve();
}