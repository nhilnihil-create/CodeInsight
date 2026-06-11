#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<typename T>
struct twodimBIT{
    private:
        vector<vector<T>> array;
        const int n;
        const int m;
    public:
        twodimBIT(int _n, int _m) : array(_n+1, vector<T>(_m+1, 0)), n(_n), m(_m) {}
        T sum(int x, int y){
            T s = 0;
            for(int i = x; i > 0; i-=i&(-i)){
                for(int j = y; j > 0; j-=j&(-j)){
                    s += array[i][j];
                }
            }
            return s;
        }
        T sum(int x1, int y1, int x2, int y2){
            return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
        }
        void add(int x, int y, T k){
            for(int i = x; i <= n; i+=i&(-i)){
                for(int j = y; j <= m; j+=j&(-j)){
                    array[i][j] += k;
                }
            }
        }
};

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	twodimBIT<int> train(n+1, n+1);
	rep(i,m){
		int l, r;
		cin >> l >> r;
		train.add(l, r, 1);
	}
	rep(i,q){
		int p, q;
		cin >> p >> q;
		cout << train.sum(p, p, q, q) << endl;
	}
	return 0;
}