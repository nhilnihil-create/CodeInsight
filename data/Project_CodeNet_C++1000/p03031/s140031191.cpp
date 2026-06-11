#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N,M; cin>>N>>M;
    vector<set<int>> k(M);
    cin.ignore();
    rep(i,M){
        int s; cin>>s;
        rep(j,s){
            int t; cin>>t;
            k[i].insert(t-1);
        }
    }
    vector<int> p(M);
    rep(i,M) cin>>p[i];

    int ans=0;
    // switchの入れ方ビット探索
    for(int i=0; i< (1<<N);i++){
        bitset<10> bit(i);
        bool flg=true;
        // 各電球について
        for(int j=0;j<M ; j++){
            int sch = 0;
            // switchが入っていたら
            for(int a=0; a<N; a++){
                if(bit.test(a)){
                    if(k[j].count(a)){
                        sch++;
                    }
                }
            }
            if(sch%2!=p[j]){
                flg=false;
            }
        }
        if(flg) ans++;
    }
    cout << ans << endl;
    // for(int x:k[0]){
    //     cout << x << " ";
    // }cout << endl;
}
