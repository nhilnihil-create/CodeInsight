#include <iostream>
#include <set>
#include <utility>

using namespace std;
typedef pair<int, int> P;

int h, w, n;
int x[200005], y[200005];
set<P> S, T;

int main(void)
{
	cin >> h >> w >> n;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	
	for(int i = 1; i <= n; i++) S.insert(make_pair(x[i], y[i]));
	for(auto it = S.begin(); it != S.end(); it++){
		if(S.count(make_pair(it->first-1, it->second)) == 0){
			if(it->first > 1) T.insert(make_pair(it->first-1, it->second));
		}
	}
	for(int i = 1; i <= min(h, w); i++) S.insert(make_pair(min(i,h), min(w+1,i+1)));
	
	int len = 0;
	for(int i = 1; i <= h-1; i++){
		len++;
		while(S.size() && S.begin()->first == i){
			len = min(len, S.begin()->second-1);
			S.erase(S.begin());
		}
		while(T.size() && T.begin()->first == i){
			if(T.begin()->second <= len){
				cout << i << endl;
				return 0;
			}
			T.erase(T.begin());
		}
	}
	cout << h << endl;
	return 0;
}