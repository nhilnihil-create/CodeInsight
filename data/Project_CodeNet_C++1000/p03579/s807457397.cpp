#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int N, M;
vector<int> G[100010];
bool used[100010][2];

int main(){

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<pii> q;
    q.push(pii(0, 0));
    used[0][0] = true;
    while(q.size()){
        pii p = q.front(); q.pop();
        int pos = p.first;
        int flg = p.second;
        for(int npos : G[pos]){
            if(used[npos][flg^1]) continue;
            q.push(pii(npos, flg^1));
            used[npos][flg^1] = true;
        }
    }
    
    ll zero = 0;
    ll one = 0;
    ll zo = 0;
    for(int i = 0; i < N; i++){
        if(used[i][0] && used[i][1]) zo++;
        else if(used[i][0] && !used[i][1]) zero++;
        else if(!used[i][0] && used[i][1]) one++;
    }
    ll sum = zero * one + zo * zero + zo * one + zo * (zo - 1) / 2;
    sum -= M;
    cout << sum << endl;

    return 0;
}
