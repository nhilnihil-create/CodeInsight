#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

int main(){
    int N, M;
    cin >> N >> M;
    vector<pii> ids(M);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        ids[i]={b, a};
    }
    sort(all(ids));
    int ans=0, cur=-1;
    for(int i=0; i<M; i++){
        if(cur <= ids[i].second){
            cur=ids[i].first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}