#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
ll a , k[100005] , q , r , l;
string n;
int main() {
    cin >> a >> q >> n;
	for(int s = 0; s < a; s++){
		if(n[s] == 'A' && n[s + 1] == 'C'){
		    k[s + 1] = k[s] + 1;
        }
		else{
            k[s + 1] = k[s];
        }
	}
	for(int s = 0; s < q; s++){
		cin >> r >> l;
		cout << k[l - 1] - k[r - 1] << endl;
	}
}