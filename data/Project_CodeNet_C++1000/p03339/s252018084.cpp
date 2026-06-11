#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=int(a); i<int(b); ++i)
#define FORD(i,a,b) for(int i=int(a); i<int(b); --i)
#define REP(i,N) for(int i=0; i<int(N); ++i)
#define REPD(i,N) for(int i=0; i<int(N); --i)
#define PB push_back
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7
#define MAXR 100000 //配列の最大のrenge

int main() {
    ll N; cin >> N;
    string S; cin >> S;
    vector<int> num(N);
    num[0] = count(S.begin()+1, S.end(),'E');
    FOR(i,1,N) {
        int tmp = num[i-1];
        if (S[i] == 'E') tmp--;
        if (S[i-1] == 'W') tmp++;
        num[i] = tmp;
    }
    
    int ans = *min_element(ALL(num));
    cout << ans;
}