#include<bits/stdc++.h>
using namespace std;

int id[200003] , N;

int main(){
	cin >> N;
	for(int i = 1 , x ; i <= N ; ++i){cin >> x; id[x] = i;}
	int mx = 0 , cnt = 0;
	for(int i = 1 ; i <= N ; ++i)
		mx = max(mx , id[i] > id[i - 1] ? ++cnt : (cnt = 1));
	cout << N - mx; return 0;
}
