#include<algorithm>
#include<complex>
#include<ctype.h>
#include<iomanip>
#include<iostream>
#include<map>
#include<math.h>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdio.h>
#include<string>
#include<string>
#include<vector>

using namespace std;
typedef long long ll;

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("YES")
#define p_no() p("NO")

template < typename T >
void vprint(T &V){
	for(auto v : V){
    	cout << v << " ";
	}
	cout << endl;
}

const ll mod = 1e9 + 7;
const ll inf = 1e18;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N, X, Y;
    cin >> N >> X >> Y;

    vector<ll> A(N);
    FOR(i, 0, N){
        cin >> A.at(i);
    }

    if(N==1){
        // とるしかない
        p(abs(A[0]-Y));
        return 0;
    }


    ll candidate0 = abs(A[N-1] - Y);
    ll candidate1 = abs(A[N-2] - A[N-1]);

    p(max(candidate0, candidate1));
    
    return 0;
}
