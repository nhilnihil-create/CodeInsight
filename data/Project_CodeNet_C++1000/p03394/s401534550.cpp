#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define int long long
#define INF 1000000000000000
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);



signed main(){

    int N; cin >> N;
    if(N == 3){
        cout << "2 5 63";
        return 0;
    }

    mat a(6, vec(0));
    FOR(i, 1, 30001) a[i % 6].push_back(i);

    cout << "2 3 4 9 ";
    N -= 4;

    int n = min(4999LL, N / 2);
    REP(i, n){
        cout << a[2][i + 1] << " " << a[4][i + 1] << " ";
    }
    N -= n * 2;

    n = min(2499LL, N / 2);
    REP(i, n){
        cout << a[3][2 * i + 2] << " " << a[3][2 * i + 3] << " ";
    }
    N -= n * 2;

    REP(i, N){
        cout << a[0][i] << " ";
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