#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.141592653589793
#define rep(i, n) for (int i = 0; i < (n); i++)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define rrep(i, n, k) for (int i = (n); i >= (k); i--);
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T>vector<T> make_vector(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vector(size_t a, Ts... ts){return vector<decltype(make_vector<T>(ts...))>(a, make_vector<T>(ts...));}
const int MOD = 1e9+ 7;
const int INF = 2e9;

int main() {
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    cin >> A >> B >> C;
    vector<ll> AB;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            AB.push_back(A[i] + B[j]);
        }
    }
    sort(AB.rbegin(), AB.rend());
    multiset<ll> ans;
    for (int i = 0; i < Z; i++) {
        for (int j = 0; j < min(K, (int) AB.size()); j++) {
            ans.insert(C[i] + AB[j]);
        }
    }
    int count = 0;
    for (auto itr = ans.rbegin(); count < K; itr++) {
        cout << *itr << endl;
        count++;
    }
}
