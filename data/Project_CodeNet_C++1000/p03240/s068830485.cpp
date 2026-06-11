#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> X(n),Y(n),H(n);
	for(int i=0; i<n; i++) cin >> X[i] >> Y[i] >> H[i];

	set<int> s;
	set<pair<int, int>> t;

	for(int x=0; x<=100; x++){
		for(int y=0; y<=100; y++){
			for(int k=0; k<n; k++){
				if(H[k]==0){
					t.insert({X[k], Y[k]});
					continue;
				}
				s.insert(abs(X[k]-x)+abs(Y[k]-y)+H[k]);
			}
			
			if(s.size()==1){
				bool b = true;
				for(auto z:t){
					if((*begin(s)-abs(z.first-x)-abs(z.second-y))>0){
						b = false;
					}
				}

				if(b){
					cout << x << " "  << y << " " << *begin(s) << endl;
					return 0;
				}
			}
		s.clear();
		t.clear();
		}
	}

	return 0;
}