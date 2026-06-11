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



int main(){
	int X0,Y0,N; cin >> X0 >> Y0 >> N;	
	vector<pair<int,int>> V;
	vector<int> a(Y0+1);
	repp(i,0,N){
		int X,Y; cin >> X >> Y;
		V.push_back(MP(Y,X));
	}
	sort(V.begin(),V.end());
	a[1] = 1;
	auto it = V.begin();
	repp(i,1,Y0){
		a[i+1] = a[i] + 1;
		while(it != V.end() && ((*it).first <= i || ((*it).first == i+1 && (*it).second < a[i+1]))) ++it;
		while(it != V.end() && (*it).first == i+1 && (*it).second == a[i+1]){++it; ++a[i+1];}
	}
	int ans = X0;
	for(auto u : V){
		if(u.second > a[u.first]) ans = min(ans,u.second-1);
	}
	cout << ans << endl;
	return 0;
}
