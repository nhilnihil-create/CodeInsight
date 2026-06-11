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
LL C,x[MC],v[MC],s[MC];

int main(){
	cin >> N >> C;
	repp(i,1,N+1){
		cin >> x[i] >> v[i];
		s[i] = s[i-1] + v[i];
	}
	LL ans = 0;
	LL mx0 = 0 , mx1 = 0;
	repm(i,N,0){
		ans = max(ans,s[i]-x[i]+mx0);
		ans = max(ans,s[i]-2*x[i]+mx1);
		mx0 = max(mx0,s[N]-s[i-1]-2*(C-x[i]));
		mx1 = max(mx1,s[N]-s[i-1]-(C-x[i]));
	}
	cout << max(ans,mx1) << endl;
	return 0;
}
