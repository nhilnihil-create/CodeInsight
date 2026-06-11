
#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;

struct city {int no, p, y;};

bool comp(city a, city b){
    if (a.p == b.p){
        return a.y < b.y;
    }
    else{
        return a.p < b.p;
    }
}

int main(){
    int N, M; cin >> N >> M;
    vector<city> Y(M);
    rep(i,M){
        int p,y; cin >> p >> y;
        city c = {i, p, y};
        Y[i] = c;
    }

    //sort(Y.begin(), Y.end(), comp);
	sort(Y.begin(), Y.end(), comp);
    vector<string> ans(M);
    int prev_city = -1;
    int count = 1;
    rep(i,M){
        string rno;
        /* 6桁の0埋め*/
        ostringstream sout;
        sout << setfill('0') << setw(6) << Y[i].p;
        if (prev_city == Y[i].p){
            count++;
        }
        else{
            count = 1;
            prev_city = Y[i].p;
        }
        sout << setfill('0') << setw(6) << count;
        rno += sout.str();

        ans[Y[i].no] = rno;
    }
    
    rep(i,M){
        cout << ans[i] << endl;
    }

}