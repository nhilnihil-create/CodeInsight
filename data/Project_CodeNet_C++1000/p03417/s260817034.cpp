#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using P = pair<int, int>;

int main(){
	ll n,m;
    cin >> n >> m;
    ll out;
    if(n > 1 && m > 1){
        out = (n-2)*(m-2);
    }else if(n == 1 && m == 1){
        out = 1;
    }else{
        out = n + m - 3;
    }

    cout << out << endl;

	return 0;
}