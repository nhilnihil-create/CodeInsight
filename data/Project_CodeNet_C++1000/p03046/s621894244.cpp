#include <bits/stdc++.h>

#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi 3.14159265
#define oo 1000000007
#define loo 10000000000000007

#define prime 1000000007

#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, k; cin >> m >> k;
    int y = (1 << m) - 1;
    if(k > y || (m == 1 && k == 1)){
    	cout << "-1\n";
    	return 0;
    }
    if(m == 1 && k == 0){
    	cout << "0 0 1 1\n";
    	return 0;
    }
    for (int i = 0; i <= y; ++i){
    	if(i == k) continue;
    	cout << i << " ";
    }
    cout << k << " ";
    for (int i = y; i >= 0; --i){
    	if(i == k) continue;
    	cout << i << " ";
    }
    cout << k << endl;

    return 0;
}