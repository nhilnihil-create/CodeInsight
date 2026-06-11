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

const int INF = 1e9 + 7;
int N;

int main(){
	cin >> N;
	LL s = 0 , m = INF;
	repp(i,0,N){
		LL A,B; cin >> A >> B;
		s += A;
		if(A > B) m = min(m,B);
	}
	cout << (m==INF?0:s-m) << endl;
	return 0;
}
