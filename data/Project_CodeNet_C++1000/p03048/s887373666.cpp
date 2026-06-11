#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int R,G,B,N;

    cin>>R>>G>>B>>N;

    int res = 0;

    for (int r=0; r*R<=N; r++) {
	for (int g=0; r*R+g*G<=N; g++) {
	    int b = N-r*R-g*G;
	    if (b%B==0) {
		//cout<<r<<" "<<g<<" "<<b<<endl;
		res++;
	    }
	}
    }

    cout<<res<<endl;
    
    
    return 0;
}
