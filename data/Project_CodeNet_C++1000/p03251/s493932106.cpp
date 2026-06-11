#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define rsz resize
#define ins insert 
#define mp make_pair
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define ft front() 
#define bk back()
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define deb(x) cout<<#x<<" "<<x<<'\n';
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

const ll mod = 1e9+7; // 998244353;
const ll inf = 1e18; 
const ld pie = acos((ld)-1);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};



int main(){
    
	int n,m,X,Y;
	scanf("%d%d%d%d",&n,&m,&X,&Y);
	vector<int> x(n);
	vector<int> y(m);
	for(int i=0;i<n;++i){
		scanf("%d",&x[i]);
	}

	for(int i=0;i<m;++i){
		scanf("%d",&y[i]);
	}

	int mn=*min_element(all(y));
	int mx=*max_element(all(x));

	bool ok=1;
	for(int z=X+1;z<=Y;++z){
		if(z>mx&&z<=mn){
			ok=0;
			break;
		}
	}

	if(!ok) puts("No War");
	else puts("War");

	return 0;

	/*STUFF TO LOOK:	
		1. Check the constraints
		2. Corner cases(n==0||n==1)
		3. Variables in loops
		4. Make sure two ints aren’t multiplied to get a long long
		5. Don't use scanf or printf while using ios_base
		6. using the local variable of the same name when global variable was required to be used
	*/
}
