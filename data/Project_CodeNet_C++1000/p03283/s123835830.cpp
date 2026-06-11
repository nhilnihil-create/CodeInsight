#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

const ll MOD = 1e+9+7;
const int INF = 1e+9+7;

int main(){
    int N,M,Q;
    cin >> N >> M >> Q;
    int l,r;
    vector<vector<int>> s(N+1,vector<int>(N+1,0));
    vector<vector<int>> c(N,vector<int>(N,0));

    rep(i,M){
        cin >> l >> r;
        l--;
        r--;
        c[l][r]++;
    }
    
    rep(i,N){
        rep(j,N){
            s[i+1][j+1]=s[i+1][j]+s[i][j+1]-s[i][j]+c[i][j];
        }
    }


    vector<int> p(Q),q(Q);
    rep(i,Q){
        cin >> p[i] >> q[i];   
    }

    rep(i,Q){
        l = p[i];
        r = q[i];
        cout << s[r][r] - s[r][l-1] - s[l-1][r] + s[l-1][l-1] << endl;
    }
}
