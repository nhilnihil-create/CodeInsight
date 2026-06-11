#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, ans=0, tmp=INF, PC[13][13]={{0}}, A[13]={0};
vector<ll> D;

void dfs(vector<ll> v, ll id, ll lid) {
    if(lid<=id) {
        tmp = INF;
        for(int i=0;i<lid;i++) {
            if(v[i]==0) v[i] = D[i];
            else v[i] = 24-D[i];
        }
        for(int i=0;i<lid;i++) {
            for(int j=i+1;j<lid;j++) {
                ll d = abs(v[i]-v[j]);
                d = min(d, 24-d);
                tmp = min(tmp,d);
            }
        }
        ans = max(ans,tmp);
        return;
    }
    if(id>0) {
        if(D[id]==D[id-1]) {
            v[id] = 1-v[id-1];
            dfs(v,id+1,lid);
        }
        else {
            dfs(v,id+1,lid);
            v[id] = 1;
            dfs(v,id+1,lid);
        }
    }
    else {
        dfs(v,id+1,lid);
        v[id] = 1;
        dfs(v,id+1,lid);
    }
}

signed main(){
    cin >> N;
    A[0]++;
    D.push_back(0);
    for(int i=0;i<N;i++) {
        ll a;
        cin >> a;
        A[a]++;
        D.push_back(a);
    }
    sort(D.begin(), D.end());
    if(A[0]>=2||A[12]>=2) {
        cout << 0 << endl;
        return 0;
    }
    for(int i=1;i<=11;i++) {
        if(A[i]>=3) {
            cout << 0 << endl;
            return 0;
        }
    }
    vector<ll> vinit;
    vinit.resize(D.size(),0);
    dfs(vinit,1,D.size());
    cout << ans << endl;
    return 0;
}