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
typedef pair<Pii, int> PPi;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

int dist(int &x, int L, int R){
    if(L <= x && x <= R){
        return 0;
    }else if(x < L){
        int d = L - x;
        x = L;
        return d;
    }else{
        int d = x - R;
        x = R;
        return d;
    }
}

signed main(){

    int N; cin >> N;
    int L, R, n;
    vector<PPi> l(N), r(N);
    REP(i, N){
        cin >> L >> R;
        l[i] = PPi(Pii(L, R), i);
        r[i] = PPi(Pii(R, L), i);
    }

    SORT(l);
    REVERSE(l);
    SORT(r);

    vector<bool> is_used(N, false);
    
    int ans1 = 0, x = 0;
    REP(i, N){
        L = l[i].first.first;
        R = l[i].first.second;
        n = l[i].second;
        if(is_used[n]) break;
        is_used[n] = true;
        ans1 += dist(x, L, R);

        R = r[i].first.first;
        L = r[i].first.second;
        n = r[i].second;

        if(is_used[n]) break;
        is_used[n] = true;
        ans1 += dist(x, L, R);
    }
    ans1 += llabs(x);

    int ans2 = 0;
    x = 0;
    fill(is_used.begin(), is_used.end(), false);
    REP(i, N){
        R = r[i].first.first;
        L = r[i].first.second;
        n = r[i].second;
        if(is_used[n]) break;
        is_used[n] = true;
        ans2 += dist(x, L, R);

        L = l[i].first.first;
        R = l[i].first.second;
        n = l[i].second;
        if(is_used[n]) break;
        is_used[n] = true;
        ans2 += dist(x, L, R);
    }
    ans2 += llabs(x); 

    cout << max(ans1, ans2);
    
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