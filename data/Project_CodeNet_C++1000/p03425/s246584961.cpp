
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    string s="MARCH";
    vector<ll> c(5,0);

    int N;
    cin >> N;
    //入力した文字列tの1文字目がsのどれか(MARCH)ならcのカウントを増やす
    for(int i=0;i<N;i++){
        string t;
        cin >> t;
        for(int j=0; j<5; j++){
            if(t[0]==s[j]){
                c[j] ++;
            }
        }
    }

    //先頭の文字は異なっていなければいけない
    //ci*cj*ckを全てのi,j,kについて足し合わせれば良い
    ll ans=0;
    for(int i=0; i<3;i++){
        for(int j=i+1; j<4; j++){
            for(int k=j+1; k<5; k++){
                ans += c[i]*c[j]*c[k];
            }
        }
    }
    cout << ans << endl;
    return 0;

}