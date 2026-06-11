#include<bits/stdc++.h>
using namespace std;
#define M 1000005
#define ll long long

ll n, p;

int main(){
	cin >> n >> p;
	if (n == 1){
		cout << p;
		return 0;
	}
	for (ll i = (ll)sqrt(p); i > 0; i--){
		if (p % (ll)pow(i, n) == 0){
            cout << i;
            break;
		}
	}
	return 0;
}
