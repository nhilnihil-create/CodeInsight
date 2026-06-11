#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define int long long
using namespace std;

typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

void fillvec(vector<int> &a, int s, int k){
    int n = a.size();
    REP(i, k){
        a[i] = i + s;
    }
    REP(i, n - k){
        a[i + k] = n - 1 - i + s;
    }
}

signed main(){

    int N, A, B;
    cin >> N >> A >> B;

    if(A * B < N || A + B > N + 1){
        cout << -1;
        return 0;
    }

    vector< vector<int> > a(N / B + min((int)1, N % B));
    REP(i, N / B){
        a[i] = vector<int>(B);
    }
    if(N % B > 0) a[N / B] = vector<int>(N % B);

    A -= a.size();

    fillvec(a[0], 0, 0);
    FOR(i, 1, a.size()){
        fillvec(a[i], i * B, min(A, B - 1));
        A -= min(A, B - 1);
    }

    REP(i, a.size()){
        REP(j, a[i].size()){
            cout << a[i][j] + 1 << " ";
        }
    }

    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}