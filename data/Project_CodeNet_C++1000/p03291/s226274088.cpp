#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
const ll MOD = 1e9+7;
void Main(){
    string s;
    cin >> s;
    int n=s.size();
    int qnum=count(ALL(s),'?');
    vector<ll> pw(n+1);
    pw[0]=1;
    For(i,0,n) pw[i+1]=(pw[i]*3%MOD);
    ll A=0,q=0,AB=0,Aq=0,qB=0,qq=0;
    For(i,0,n){
        if(s[i]=='A') A++;
        else if(s[i]=='B') {
            AB += A;
            qB += q;
        }
        else if(s[i]=='C') {
            ans += AB * pw[qnum] % MOD;
            ans += Aq * pw[qnum-1] % MOD;
            ans %= MOD;
            ans += qB * pw[qnum-1] % MOD;
            ans += qq * pw[qnum-2] % MOD;
        }
        else{
            ans += AB * pw[qnum-1] % MOD;
            ans += Aq * pw[qnum-2] % MOD;
            ans %= MOD;
            ans += qB * pw[qnum-2] % MOD;
            ans += qq * pw[qnum-3] % MOD;
            Aq += A;
            qq += q;
            q ++;
        }
        AB %= MOD;
        Aq %= MOD;
        qB %= MOD;
        qq %= MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}