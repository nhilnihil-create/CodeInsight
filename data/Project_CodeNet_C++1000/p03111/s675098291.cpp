#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=1e9+7;

vi l;
vi bom(3, 0);
vi target(3);
int N, no=0;
ll res=INF;

void dfs(int id=0){
    if(id == N){
        ll sum=0;
        bool ok=true;
        for(int i=0; i<3; i++){
            if(bom[i] == 0) ok=false;
            sum+=abs(target[i]-bom[i]);
        }
        if(ok){
            sum+=(N-no-3)*10;
            res=min(res, sum);
        }
        return;
    }
    for(int i=-1; i<3; i++){
        if(i == -1){
            no++;
            dfs(id+1);
            no--;
        }
        else{
            bom[i]+=l[id];
            dfs(id+1);
            bom[i]-=l[id];
        }
    }
}

int main(){
    cin >> N;
    l.resize(N);
    for(auto &x: target) cin >> x;
    for(auto &x: l) cin >> x;
    dfs();
    cout << res << endl;
    return 0;
}