#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  FOR(i,0,n)
#define req(i,n) for(int i = 1;i <=n;i++)
#define pai 3.14159265358979323846
const int INF = 1001001001;
typedef long long ll;
int A[3][3], N;
bool punched[3][3];
bool ok[3][3];
using Graph = vector<vector<int>>;
vector<vector<int>> field;
vector<bool> seen;

const int MOD = 1000000007;
typedef pair<int,int> P;

//最大公約数
int gcd(int a,int b){
	if (a%b == 0){
		return b;
	}
	else{
		return gcd(b,a%b);
	}

}

//最小公倍数
int lcm(int a,int b){
	return a /gcd(a,b) * b;
}

//素数判定
bool is_prime(long long N) {
    if (N == 1) return false;
    for (long long i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; ++i) cin >> h[i];

    // 高さが全部 0 になるまでやる
    int res = 0;
    while (true) {
        // 最高高さが 0 だったらおしまい
        if (*max_element(h.begin(), h.end()) == 0) break;
        
        // 区間分割する
        int i = 0;
        while (i < N) {
            if (h[i] == 0) ++i; // 0 なら何もせずに次に進む
            else {
                ++res; // 区間の始まり
                while (i < N && h[i] > 0) {
                    --h[i]; // ついでに引いとく
                    ++i; // 区間の終わりまで一気に
                }
            }
        }
    }
    cout << res << endl;
}