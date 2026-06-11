#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<int> li(n);
	rep(i, n) cin >> li.at(i);
	vector<int> ar(n);
	rep(i, n) ar.at(i) = i;
	int min = 1000000000;
	do{
		for(int i=0; i<n-2; i++){
			for(int j=i+1; j<n-1; j++){
				for(int l=j+1; l<n; l++){
					vector<int> l0(3);
					rep(i, 3) l0.at(i) = 0;
					int sum = 0;
					sum += (l-j-1)*10;
					sum += (j-i-1)*10;
					sum += i*10;
					rep(ii, n){
						if(ii <= i){
							l0.at(0) += li.at(ar.at(ii));
						}else if(ii <= j){
							l0.at(1) += li.at(ar.at(ii));
						}else if(ii <= l){
							l0.at(2) += li.at(ar.at(ii));
						}else{
							break;
						}
					}
					sort(l0.begin(), l0.end());
					sum += abs(l0.at(0) - c);
					sum += abs(l0.at(1) - b);
					sum += abs(l0.at(2) - a);
					if(sum < min) min = sum;
				}
			}
		}
	}while(next_permutation(ar.begin(), ar.end()));
	cout  << min << endl;
	return 0;
}