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



signed main(){

    int N, A, B;
    cin >> N;

    int ans = 1000000000000;
    int sumv = 0;
    bool allsame = true;
    REP(i, N){
        cin >> A >> B;
        if(A != B) allsame = false;
        sumv += A;
        if(A > B) ans = min(ans, B);
    }

    if(allsame){
        ans = 0;
    }else{
        ans = sumv - ans;
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