#include<bits/stdc++.h>
using namespace std;

#define PII pair < int , int >
#define x first
#define y second
vector < PII > now; int N , M , K;

int main(){
	cin >> N >> M >> K;
	for(int i = 1 ; i <= K ; ++i){int x , y; cin >> x >> y; now.push_back(PII(x , y));}
	sort(now.begin() , now.end());
	int delt = 0 , ans = N;
	for(int i = 0 ; i < now.size() ; ++i)
		if(now[i].x - now[i].y > delt) ans = min(ans , now[i].x - 1);
		else if(now[i].x - now[i].y == delt) ++delt;
	cout << ans; return 0;
}