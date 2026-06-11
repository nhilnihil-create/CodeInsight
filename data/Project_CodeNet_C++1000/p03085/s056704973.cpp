#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 100100100100100100;//10^17
const ll MOD = 1000000007;


ll combination(ll n, ll r){
    if(n < r) return 0;
    if(r == 0||r == n) return 1;
    else if(r == 1) return n;
    return (combination(n - 1, r - 1) + combination(n - 1, r));
}

bool checkKaibun(string str){
    string checkStr = str;
    reverse(checkStr.begin(), checkStr.end());
    if(str == checkStr) return true;
    else return false;
}




int main(){
    char b;
    cin >> b;
    if(b == 'A')cout << 'T';
    if(b == 'C')cout << 'G';
    if(b == 'G')cout << 'C';
    if(b == 'T')cout << 'A';
    cout << endl;
}

