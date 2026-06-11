#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl;

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAX { 1000010 };
const ll MOD { 1000000007 };
const double PI = acos(-1.0);

int main(){
	ios::sync_with_stdio(false);
    int N, X;
    cin >> N >> X;

    int sum_N = 0;
    int min = MAX;
    int aux_N = N;
    while(aux_N--){
        int aux;
        cin >> aux;
        sum_N+= aux;
        if(aux < min) min = aux;
    }
    X -= sum_N;

    cout << N + X/min << endl;

	return 0;
}