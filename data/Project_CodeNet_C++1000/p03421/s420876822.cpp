#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    if (N <  A + B - 1 || N > 1LL * A*B) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> T;
	int S=N-A;
	int cur=N;
	rep(i,A) {
		int num=min(B-1,S)+1;
		S-=num-1;
		rep(j,num) T.push_back(cur-num+1+j);
		cur-=num;
	}
	reverse(T.begin(), T.end());
	for(auto v : T) cout<<v<<" ";
	cout<<endl;
    return 0;
}