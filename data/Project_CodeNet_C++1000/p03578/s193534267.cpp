#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int N;
    cin >> N;
    map<int,int>Dcounter;
    map<int,int>Mcounter;
    
    for (int i=0; i<N; i++){
        int di;
        cin >> di;
        Dcounter[di]++;
    }
    int M;
    cin >> M;
    vector<int>Ts(M);
    for (int i=0; i<M; i++){
        int mi;
        cin >> mi;
        Mcounter[mi]++;
        Ts[i] = mi;
    }

    for (int i=0; i<M; i++){
        int Ti = Ts[i];
        if (Dcounter[Ti] > 0)Dcounter[Ti]--;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}