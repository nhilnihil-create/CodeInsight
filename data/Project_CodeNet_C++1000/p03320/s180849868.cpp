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

vector<LL> ans;

LL S(LL x){
	LL ret = 0;
	for(; x ; x /= 10) ret += x%10;
	return ret;
}

void check(LL x){
	LL y = S(x);
	while(ans.size()){
		LL p = *ans.rbegin();
		if(p*y > x*S(p)) ans.pop_back();
		else break;
	}
	ans.push_back(x);
}

int main(){
	int K; cin >> K;
	repp(i,1,100) check(i);
	LL a = 0 , b = 1;
	while(a < 1e12){
		repp(i,100,1000) check(i*b+a);
		a = a*10+9;
		b *= 10;
	}
	repp(i,0,K) cout << ans[i] << endl;
	return 0;
}
