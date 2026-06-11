#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll H,W,N,sr,sc;
    cin >> H >> W >> N;
    cin >> sr >> sc;
    string S,T;
    cin >> S >> T;
    map<char, ll> SS, TT;
    bool flag = false;
    ll L,R,U,D;
    L=sc-1;
    R=sc-1;
    U=sr-1;
    D=sr-1;
    rep(i,N){
        if(S[i]=='L'){
            L--;
        }else if(S[i]=='R'){
            R++;
        }else if(S[i]=='U'){
            U--;
        }else if(S[i]=='D'){
            D++;
        }
        if(L < 0 || W <= L){
            flag = true;
            break;
        }else if(R < 0 || W <= R){
            flag = true;
            break;
        }else if(U < 0 || H <= U){
            flag = true;
            break;
        }else if(D < 0 || H <= D){
            flag = true;
            break;
        }
        if(T[i]=='L'){
            R--;
        }else if(T[i]=='R'){
            L++;
        }else if(T[i]=='U'){
            D--;
        }else if(T[i]=='D'){
            U++;
        }
        if(W <= L){
            L = W-1;
        }
        if(R < 0){
            R = 0;
        }
        if(H <= U){
            U = H -1;
        }
        if(D < 0){
            D = 0;
        }
        /*
        SS[S[i]]++;
        TT[T[i]]++;
        if(sc <= SS['L'] - max(TT['R'], W-1) ||
            W-sc < SS['R'] - max(TT['L'], W-1) ||
            sr <= SS['U'] - TT['D'] ||
            H-sr < SS['D'] - TT['U']){
            flag = true;
            break;
        }*/   
    }
    cout << (flag?"NO":"YES") << endl;
}
