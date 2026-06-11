#include<bits/stdc++.h>
using namespace std;

const long long INF = 1000000000;

typedef long long ll;

#define writeln(n) cout<<n<<"\n"
#define rep(i,n) for(int i=0; i<(n); ++i)

typedef pair<int, int> P;
typedef pair<string, int> Psi;

int k=0;
int n=0;

int dfs(bool three, bool five, bool seven, ll target , int cnt){

	int ans =0;

	if(cnt ==k) {
		if( three && five && seven && target <=n){
		return 1;
		}
		return 0;
	}

	for(int i=3; i<=7;  i +=2){

		if(i ==3){
			ans +=dfs(true,five,seven, target*10+i, cnt+1);
		}
		if(i ==5){
			ans +=dfs(three,true,seven, target*10+i, cnt+1);
		}
		if(i ==7){
			ans +=dfs(three,five,true, target*10+i, cnt+1);
		}

	}
	return ans;
}
int digit(int x){
	int cnt=0;

	while(x){
		cnt++;
		x /=10;


	}

	return cnt;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin>>n;

	k = digit(n);

	int sum =0;

	for(int i=k; i>=3; i--){
	sum +=dfs(false,false,false,0,0);
	k--;
	}
	writeln(sum);




}

