#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	int R, G, B, N, ans = 0, c;
	
	cin >> R >> G >> B >> N;
	
	for(int i = 0; i <= (int)N/R+1; i++){
		for(int j = 0; j <= (int)N/G+1; j++){
			if(i*R + j*G <=N && (N - i*R - j*G) % B == 0){
				 ++ans;
				 //cout << i << " " << j << " " << (N - i*R + j*G) /B << endl;
			 }
		}
	}
	cout << ans;

}
