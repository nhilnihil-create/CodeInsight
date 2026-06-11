#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

const int MC = 1e5 + 3;
int N;
LL C,x[MC],v[MC],s[MC],t[MC];

int main(){
	cin >> N >> C;
	repp(i,1,N+1){
		cin >> x[i] >> v[i];
		s[i] = s[i-1] + v[i];
	}
	repm(i,N,0) t[i] = t[i+1] + v[i];
	LL ans = 0;
	LL mx = 0;
	repm(i,N,0){
		ans = max(ans,s[i]-x[i]+mx);
		mx = max(mx,t[i]-2*(C-x[i]));
	}
	mx = 0;
	repp(i,1,N+1){
		ans = max(ans,t[i]-C+x[i]+mx);
		mx = max(mx,s[i]-2*x[i]);
	}
	cout << ans << endl;
	return 0;
}
