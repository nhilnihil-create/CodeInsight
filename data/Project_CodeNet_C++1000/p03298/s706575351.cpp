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
    string S; cin >> S;

    string S1 = S.substr(0, N);
    string S2 = S.substr(N, 2 * N);
    REVERSE(S2);

    map<string, int> m;

    REP(i, 1 << N){
        string s1 = "", s2 = "";
        REP(j, N){
            if(((i >> j) & 1) == 1){
                s1 += S1[j];
            }else{
                s2 += S1[j];
            }
        }
        m[s1 + " " + s2] += 1;
    }

    int ans = 0;
    REP(i, 1 << N){
        string s1 = "", s2 = "";
        REP(j, N){
            if(((i >> j) & 1) == 0){
                s1 += S2[j];
            }else{
                s2 += S2[j];
            }
        }
        ans += m[s1 + " " + s2];
    }

    cout << ans;
    
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