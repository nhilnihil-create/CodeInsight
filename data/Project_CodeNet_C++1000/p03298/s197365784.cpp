#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int N;
char SA[20];
char SB[20];
string tmpA;
string tmpB;

typedef map<pair<string, string>, ll> PP;

void dfs(char S[], int v, PP& ma){
    if(v == N){
        //reverse(tmpB.begin(), tmpB.end());
        ma[make_pair(tmpA, tmpB)]++;
        //reverse(tmpB.begin(), tmpB.end());
    }
    else{
        tmpA.push_back(S[v]);
        dfs(S, v+1, ma);
        tmpA.pop_back();

        tmpB.push_back(S[v]);
        dfs(S, v+1, ma);
        tmpB.pop_back();
    }
}

int main(){
    cin >> N;
    string X;
    cin >> X;

    REP(i,N){
        char c;
        c = X[i];
        SA[i] = c;
    }
    for(int i = 2*N-1; i >= N; i--){
        char c;
        c = X[i];
        SB[2*N-1 - i] = c;
    }

    ll ans = 0;
    PP A, B;
    tmpA = "";
    tmpB = "";
    dfs(SA, 0, A);

    dfs(SB, 0, B);

    for(auto&& p : A){
        ll bb = B[p.first];
        ll aa = p.second;
        //ans += min(aa, bb);
        ans += aa*bb;
        //cout << p.first.first << " " << p.first.second << endl;
    }

    cout << ans << endl;
    return 0;
}
