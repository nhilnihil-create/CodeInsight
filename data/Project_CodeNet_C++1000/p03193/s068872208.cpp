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

    int n, H, W;
    cin>>n>>H>>W;
    int res = 0;
    while (n--) {
	int x,y;
	cin>>x>>y;
	if (x>=H && y>=W) res++;
    }

    cout<<res<<endl;
    return 0;
}
