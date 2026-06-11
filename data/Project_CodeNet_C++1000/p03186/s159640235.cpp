#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
	ll a, b, c; cin >> a >> b >> c;
    if(a+b+1 >= c){
        cout << b+c << endl;
    }
    else cout << b+(a+b+1) << endl;
    system("pause");
}
