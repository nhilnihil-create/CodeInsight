#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

int main(){
    ll H,W,N;
    cin >> H >> W >> N;
    ll sr,sc;
    cin >> sr >> sc;
    ll gr=H-sr+1,gc=W-sc+1;
    string S,T;
    cin >> S >> T;
    bool ans=true;
    rep(i,N){
        if (S[i]=='L'){
            sc--;
        }
        else if (S[i]=='R'){
            gc--;
        }
        else if (S[i]=='U'){
            sr--;
        }
        else {
            gr--;
        }
        if (sc==0||gc==0||sr==0||gr==0){
            ans=false;
            break;
        }
        if (T[i]=='L'&&gc<W){
            gc++;
        }
        else if (T[i]=='R'&&sc<W){
            sc++;
        }
        else if (T[i]=='U'&&gr<H){
            gr++;
        }
        else if (T[i]=='D'&&sr<H){
            sr++;
        }
    }
    if (ans){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}