
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()


int main(){
    ll a, b, k;
    cin >> a >> b >> k;
    
    //kがb-aの半分より大きい場合には全てを出力する
    if(b-a <= 2*k-1){
        for(int i=a; i<=b; i++){
            cout << i << endl;
        }
        return 0;
    }


    rep(i,k) cout << a+i << endl;
    //昇順に出力するため一旦ベクトルに入れて逆順にする
    vector<ll> temp(k);
    rep(i,k) temp[i] = b-i;
    reverse(all(temp));
    rep(i,k) cout << temp[i] << endl;

}