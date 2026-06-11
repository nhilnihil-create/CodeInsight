#include<bits/stdc++.h>
using namespace std;

int main(){
#define pii pair < int , int >
	vector < pii > ed; int N; cin >> N;
	if(N & 1){
		for(int i = 1 ; i < N ; ++i) ed.push_back(pii(i , N));
		--N;
	}
	for(int i = 1 ; N - i + 1 > i ; ++i)
		for(int j = i + 1 ; j < N - i + 1 ; ++j)
			if(j != i && j != N - i + 1){
				ed.push_back(pii(i , j));
				ed.push_back(pii(N - i + 1 , j));
			}
	cout << ed.size() << endl;
	for(auto t : ed) cout << t.first << ' ' << t.second << endl;
	return 0;
}