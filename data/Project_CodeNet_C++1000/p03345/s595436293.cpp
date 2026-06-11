#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}

const ll MAX = 1e18;

int main(){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    if(abs(a-b) > MAX) cout << "Unfair" << endl;
    else{
        if(k%2 == 0) cout << a-b << endl;
        else cout << b-a << endl;
    }
    return 0;
}
