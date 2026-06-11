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

LL BS(LL x , LL y , LL p){
	if(y-x<2) return x;
	LL z = (x+y)/2;
	return (z/2) * ((z+1)/2) < p ? BS(z,y,p) : BS(x,z,p);
}

int main(){
	int Q; cin >> Q;
	repp(rep_t,0,Q){
		LL A,B; cin >> A >> B;
		cout << (A == B ? 2*(A-1) : BS(1,A+B+1,A*B)-2) << endl;
	}
	return 0;
}
