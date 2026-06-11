#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))

#define INF 2e9
#define INF_LL 1LL<<60
#define ll long long
#define MOD 1e9+7
#define MAX_V
const double PI=3.14159265358979323846;

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
#define print_line(vec, n) {for(int i=0;i<(n-1);i++) cout << (vec)[i] << " "; cout << (vec)[(n)-1] << endl;}
template<class T> void print(const T& x){cout << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}} premain; 

bool compare_by_b(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
#ifdef LOCAL
    ifstream in("../in.txt"); cin.rdbuf(in.rdbuf());
#endif
    int N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> point(N);
    vector<pair<ll, ll>> x_ascend(N);
    vector<pair<ll, ll>> y_ascend(N);
    REP(i, N){
        cin >> point[i].first >> point[i].second;
        x_ascend[i] = point[i];
        y_ascend[i] = point[i];
    } 

    sort(x_ascend.begin(), x_ascend.end());  
    sort(y_ascend.begin(), y_ascend.end(), compare_by_b);

    ll answer = 1LL * (x_ascend[N-1].first - x_ascend[0].first) * (y_ascend[N-1].second - y_ascend[0].second);

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int l=0; l<N; l++){
                for(int m=l+1; m<N; m++){
                    ll internal_point = 0;
                    ll x_left = x_ascend[i].first;
                    ll x_right = x_ascend[j].first;
                    ll y_down = y_ascend[l].second;
                    ll y_up = y_ascend[m].second;

                    for(int n=0; n<N; n++){
                        if(x_left <= point[n].first && point[n].first <= x_right){
                            if(y_down <= point[n].second && point[n].second <= y_up){
                                internal_point++;
                            }
                        }
                    }

                    if(internal_point >= K){
                        answer = min(answer, 1LL*(x_right - x_left)*(y_up - y_down));
                    }
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}