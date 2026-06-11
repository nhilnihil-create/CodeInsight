#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
const int MOD = 1000000007;

struct city{
    int id, p, year;
};

bool comp(city a, city b){
    if (a.p == b.p){
        return a.year < b.year;
    }
    else{
        return a.p < b.p;
    }
}

int main(){
    int N, M; cin >> N >> M;

    vector<city> P;
    rep(i,M){
        int p, y;
        cin >> p >> y;
        city c = {i,p,y};
        P.push_back(c);
    }

    sort(P.begin(), P.end(), comp);


    int prev_pre = -1;
    int count = 0;
    vector<string> ans(M, "");
    rep(i,M){
        city c = P[i];
        
        string t = "";
        ostringstream sout;
        sout << setfill('0') << setw(6) << c.p;
        if(prev_pre == c.p){
            count++;
        }
        else{
            count = 1;
            prev_pre = c.p;
        }
        sout << setfill('0') << setw(6) << count;
        t = sout.str();

        ans[c.id] = t;

    }

    rep(i,M){
        cout << ans[i] << endl;
    }

}