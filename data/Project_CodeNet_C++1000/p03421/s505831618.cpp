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

int N,A,B;

int main(){
	cin >> N >> A >> B;
	if(A+B-1>N || (LL)A*B<(LL)N){
		cout << -1 << endl;
	} else {
		int x = N - A;
		int m = 0;
		while(m<N){
			int y = 0;
			if(x>=B-1){
				y = B;
			} else {
				y = x+1;
			}
			repm(i,m+y,m) cout << i << ' ';
			m += y;
			x -= y-1;
		}
		cout << endl;
	}
	return 0;
}