#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int s_int(string s){
    return atoi(s.c_str());
}
vector<int> v(4,0);
bool ok = 0;
void solve(int now, int cnt, vector<bool> ope){
    if(cnt == 4){
        if(now == 7 && ok == 0){
            rep(i,4){
                if(i < 3){
                    if(ope[i] == 0) cout << v[i] << "+";
                    else cout << v[i] << "-";
                }else cout << v[i] << "=7" << endl;
            }
            ok = 1;
            return ;
        }
    }else{
        vector<bool> ope1,ope2;
        ope1 = ope;
        ope2 = ope;
        ope1.push_back(0);
        ope2.push_back(1);
        solve(now + v[cnt], cnt + 1, ope1);
        solve(now - v[cnt], cnt + 1, ope2);
    }
}
int main(){
    cout << fixed << setprecision(10);
    string s;
    cin >> s;
    rep(i,4) v[i] = s_int(s.substr(i,1));
    vector<bool> ope;
    solve(v[0],1, ope);
    return 0;
}
