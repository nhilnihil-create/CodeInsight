#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using v2 = vector<vector<int>>;

int D;
ll G;
ll M;

int main(){
	cin >> D >> G;
	M = 100000000000;
	v2 pc(D, vector<int>(3));
	rep(i, D){
		cin >> pc.at(i).at(0);
		cin >> pc.at(i).at(1);
	}

	rep(bit, (1<<D)){
		rep(i, D){
				pc.at(i).at(2) =0;
		}
		ll sum = 0;
		ll m = 0;
		rep(i, D){
			if(bit & (1<<i)){
				sum += (100*(i+1)*pc.at(i).at(0) + pc.at(i).at(1));
				m += pc.at(i).at(0);
				pc.at(i).at(2) = 1;
			}
		}
		if(sum >= G){
			M = min(M, m);
		}else{
			for(int i = D-1; i>=0; --i){
				if(pc.at(i).at(2) == 0){
					int k = pc.at(i).at(0);
					for(int j = 0; j < k; j++){
						sum += 100*(i+1);
						m++;
						if(sum >= G){
							M = min(M, m);
							break;
						}
					}
					if(sum >= G) break;
				}
			}
		}
	}
	cout << M << endl;

}
