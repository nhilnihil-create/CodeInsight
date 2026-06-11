#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<ll,ll> P;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
#define IINF 1e9

string lexi(string s, string t){

}

int main(void){
    string s,t;
    cin >> s >> t;
    vector<string> tmp;
    int l = s.size() - t.size() + 1;
    REP(i,max(0, l)){
        bool can = true;

        string t2 = s;
        REP(j,t.length()){
            if(i+j > s.size() - 1){
                can = false;
                break;
            }
            if(s[i+j] != '?' && s[i+j] != t[j]){
                can = false;
                break;
            }
            t2[i+j] = t[j];
        }
        if(can){
            FOR(k,0,s.length()){
                if(t2[k] == '?') t2[k] = 'a';
            }
            tmp.push_back(t2);
        }
    }
    sort(tmp.begin(),tmp.end());
    if(tmp.empty()) cout << "UNRESTORABLE" << endl;
    else cout << tmp[0] << endl;
    return 0;
}