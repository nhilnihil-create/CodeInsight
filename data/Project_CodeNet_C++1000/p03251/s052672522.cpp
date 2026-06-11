#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int>xs(N);
    vector<int>ys(M);

    for (int i=0; i<N; i++){
        cin >> xs.at(i);
    }
    
    for(int j=0; j<M; j++){
        cin >> ys.at(j);
    }

    int Zmi, Zma;
    Zmi = X+1;
    Zma = Y;

    for (int i=Zmi; i<=Zma; i++){
        if (X < i && i <= Y && *max_element(xs.begin(), xs.end()) < i && *min_element(ys.begin(), ys.end()) >= i){
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
    
}