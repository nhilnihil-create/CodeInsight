// B - 1 Dimensional World's Tale
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(x) (x).begin(),(x).end()
#define rp(i,s,e) for(int i=(s);i<(e);++i)

int N,M,X,Y;
vi XX,YY;

bool solve(){
	vector<pair<int,int>> V;//<point,state:[0|1]=[A|B]>
	V.emplace_back(X, 0);
	rp(i,0,N) V.emplace_back(XX[i], 0);
	V.emplace_back(Y, 1);
	rp(i,0,M) V.emplace_back(YY[i], 1);

	sort(all(V));

	int pre_point, pre_state;
	int point, state;
	tie(pre_point, pre_state) = V[0];
	rp(i, 1, V.size()){
		tie(point, state) = V[i];
		if(pre_state > state) return false;
		else if(pre_state < state){
			if(pre_point == point) return false;
		}
		pre_point = point;
		pre_state = state;
	}

	return true;
}

int main(){
	cin>>N>>M>>X>>Y;
	XX.resize(N); rp(i, 0, N) cin>>XX[i];
	YY.resize(M); rp(i, 0, M) cin>>YY[i];
	cout<< (solve()? "No War":"War") <<endl;
}