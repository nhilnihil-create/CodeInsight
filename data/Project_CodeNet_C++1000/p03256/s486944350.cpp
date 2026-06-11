#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb(x) push_back(x)

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2e5 + 5;

string s;
int n, m, cnt;
int a[MAXN], b[MAXN];
int d[2][MAXN], val[MAXN];
queue <int> Q;
vector <int> E[MAXN];
bool bio[MAXN];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    cin >> s;
    REP(i, n)
        val[i] = s[i] - 'A';

    REP(i, m){
        cin >> a[i] >> b[i];
        a[i] --; b[i] --;
        E[a[i]].pb(b[i]);
        E[b[i]].pb(a[i]);

        d[val[a[i]]][b[i]] ++; d[val[b[i]]][a[i]] ++;
    }

    REP(i, n){
        if(!d[0][i] || !d[1][i]){
            Q.push(i);
            bio[i] = true;
            cnt ++;
        }
    }

    while(!Q.empty()){
        int x = Q.front();
        Q.pop();

        for(auto it : E[x]){
            d[val[x]][it] --;
            if(!d[val[x]][it] && !bio[it]){
                bio[it] = true;
                Q.push(it);
                cnt ++;
            }
        }
    }

    if(cnt == n)
        cout << "No";
    else
        cout << "Yes";
}
