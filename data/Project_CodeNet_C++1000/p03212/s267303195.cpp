#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=1e9+7;

ll res=0;

void dfs(int &N, ll m){
    for(int i=3; i<=7; i+=2){
        m+=i;
        if(m > N){
            m-=i;
            continue;
        }
        ll tmp=m;
        vector<bool> ok(3, 0);
        while(tmp > 0){
            ok[(tmp%10-3)/2]=true;
            tmp/=10;
        }
        if(ok[0] && ok[1] && ok[2]){
            res++;
        }
        if(m*10 < N) dfs(N, m*10);
        m-=i;
    }
}

int main(){
    int N; cin >> N;
    dfs(N, 0);
    cout << res << endl;
    return 0;
}