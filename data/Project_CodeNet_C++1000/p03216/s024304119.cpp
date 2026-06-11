#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);

    int N; cin >> N;
    string S; cin >> S;
    int Q; cin >> Q;
    rep(q,Q){
        ll ret = 0;
        int k;
        cin >> k;
        ll a = 0 , b = 0 , c = 0;
        ll ab = 0;
        // a := 区間に含まれる D の個数
        // b := 区間に含まれる M の個数
        // C := 区間に含まれる C の個数

        // ここにk-DMC数を計算する処理を書く

        for(int i=0;i<k;i++){
            // 0 番目から k-1番目までは、そのまま集合に入れていく感じで
            if(S[i]=='D')a++;
            else if(S[i]=='M'){
                ab += a;
                b++;
            }
            else if(S[i]=='C')ret += ab;
        }
        for(int i=k;i<N;i++){
            // k番目からN番目は
            // まず、一番左の要素を出さないといけない
            if(S[i-k]=='D'){
                ab -= b;
                a--;
            }
            else if(S[i-k]=='M')b--;
            
            if(S[i]=='D'){
                a++;
            }else if(S[i]=='M'){
                ab += a;
                b++;
            }else if(S[i]=='C')ret += ab;
        }
        cout << ret << endl;
    }

}