#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define int long long
#define double long double
#define all(a) a.begin(), a.end()
#define debug(x) cout << #x << " = " << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

signed main(void){

    //条件の言い換え: どの要素も総和と互いに素でなく、かつ全ての要素の最大公約数は1
    //3の倍数出ない2の倍数と2の倍数でない3の倍数を混在させつつ、総和を6の倍数に保つことができれば良い
    //2または3の倍数: 20000個, 総和は6の倍数なので要素数は足りる

    int N; cin >> N;
    if(N == 3){ cout << 2 << ' ' << 5 << ' ' << 63 << endl; return 0; }
    if(N == 4){ cout << 2 << ' ' << 5 << ' ' << 20 << ' ' << 63 << endl; return 0; }

    vector<int> two(9998), three(4998), six(5000);
    rep(i, 4999){
        six[i] = (i + 1) * 6;
        three[i] = six[i] + 9;
        two[i * 2] = six[i] + 2;
        two[i * 2 + 1] = six[i] + 4;
    }
    six[4999] = 30000;

    deque<int> ans = { 4, 2, 3, 9 };
    auto answer = [&](){
        rep(i, ans.size()){
            if(i > 0)cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    };
    #define judge if(ans.size() == N){ answer(); return 0; }

    //4 ~ 5004
    rep(i, 5000){
        ans.push_back(six[i]);
        judge;
    }

    //5004 ~ 10003
    rep(i, 4999){
        ans.pop_back();
        ans.push_front(two[i * 2]);
        ans.push_front(two[i * 2 + 1]);
        judge;
    }

    //10003 ~ 15002
    rep(i, 4999){
        ans.push_back(six[i + 1]);
        judge;
    }

    //15002 ~ 17501
    rep(i, 2499){
        ans.pop_back();
        ans.push_front(three[i * 2]);
        ans.push_front(three[i * 2 + 1]);
        judge;
    }

    //17501 ~ 20000
    rep(i, 2499){
        ans.push_back(six[i + 2501]);
        judge;
    }

}