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

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int all = 1, odd = 1;
    for(int i = 0; i < n; i++){
        all *= 3;
        if(a[i]%2 == 0) odd *= 2; //すべてのiについてbiが奇数になる個数
    }
    cout << all-odd << endl;
    return 0;
}
