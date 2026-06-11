#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    int X[100010];
    for(int i=0; i<N; ++i) cin >> X[i];
    sort(X, X+N, greater<int>());
    int P=1;
    while(X[P]*2>X[0] && P<N) ++P;
    if(P==N) cout << X[0] << " " << X[N-1] << endl;
    else if(X[P]>=X[0]-X[P-1]) cout << X[0] << " " << X[P] << endl;
    else cout << X[0] << " " << X[P-1] << endl;
	return 0;
}
