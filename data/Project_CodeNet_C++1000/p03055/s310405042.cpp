#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N;
    cin >> N;
    if(N == 1){
        printf("First\n");
        return 0;
    }
    vector<vector<int>> G(N);
    int a, b;
    for (int i = 0; i < N-1; i++) {
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<int> q;
    vector<int> ds(N, inINF);
    ds[0] = 0;
    q.push(0);
    int tmp;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        for (int v : G[tmp]){
            if(ds[v] < inINF){
                continue;
            }
            ds[v] = ds[tmp] + 1;
            q.push(v);
        }
    }


    int m = 0;
    int ind;
    for (int i = 0; i < N; i++) {
        if(ds[i] > m){
            ind = i;
            m = ds[i];
        }
    }

    fill(ALL(ds), inINF);
    q.push(ind);
    ds[ind] = 0;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        for (int v : G[tmp]){
            if(ds[v] < inINF){
                continue;
            }
            ds[v] = ds[tmp] + 1;
            q.push(v);
        }
    }
    m = 0;    
    for (int i = 0; i < N; i++) {
        if(ds[i] > m){
            ind = i;
            m = ds[i];
        }
    }
    
    if(m % 3 == 1){
        printf("Second\n");
    }
    else{
        printf("First\n");
    }

}  