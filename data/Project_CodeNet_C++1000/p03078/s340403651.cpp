#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
    int X,Y,Z,K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A,B,C;
    vector<ll> total(3001, 0);
    vector<char> moji;
    
    //おいしさを配列に。
    rep(i,X){
        ll x;
        cin >> x;
        A.push_back(x);
    }
    
    rep(i,Y){
        ll x;
        cin >> x;
        B.push_back(x);
    }
    
    rep(i,Z){
        ll x;
        cin >> x;
        C.push_back(x);
    }
    
    //それぞれを大きい順にする
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());
    
    
    //おいしさ合計列を作る
    rep(i,X){
        rep(j,Y){
            if((i+1)*(j+1) > K)break;
            rep(k,Z){
                if((i+1)*(j+1)*(k+1) > K) break;
                total.push_back(A[i]+B[j]+C[k]);
                //必要以上のサイズだったら小さい数を除去
                /*
                if( total.size() >= K+1 ){
                    sort(total.begin(), total.end());
                    reverse(total.begin(), total.end());
                    total.pop_back();
                }
                */
            }
        }
    }
    
    sort(total.begin(), total.end());
    reverse(total.begin(), total.end());
    
    for(int i=0; i<K; i++){
        cout << total[i] << endl;
    }
    
    /*
    for(ll x:C){
        cout << x << " ";
    }
    */
    
    
}
