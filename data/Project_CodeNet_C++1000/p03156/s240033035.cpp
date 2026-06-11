#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int A,B;
	cin >> A >> B;
	vector<int> P(N);
	rep(i,N)cin >> P[i];
	int a = 0 ,b = 0,c = 0;
	rep(i,N){
		if(P[i]<=A)a++;
		else if(P[i] <= B)b++;
		else c++;
	}
		cout << min({a,b,c}) << endl;
}