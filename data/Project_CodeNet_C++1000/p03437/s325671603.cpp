#include <bits/stdc++.h>
#include<iomanip>
#define ll long long
#define pb push_back
#define mp make_pair
#define MOD 1000000007
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   	ll a,b;
   	cin >> a >> b;
   	if(a%b) cout << a;
   	else cout << -1;
   	cout << "\n";
    return 0;
}

