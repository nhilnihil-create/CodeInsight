#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
#define INF 100000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    ll N; cin >> N;
    string S; cin >> S;
    
    int cntW=0;
    int cntE=0;
    rep(i,S.size()){
        if (S[i]=='W') cntW++;
        else cntE++;
    }
    
    vector <int> W(N,0);
    vector <int> E(N,0);
    rep(i,S.size()){
        if (i==0){
            if (S[i]=='W') W[0]=1;
            else E[0]=1;
        }else{
            if (S[i]=='W'){
                W[i]=W[i-1]+1;
                E[i]=E[i-1];
            }
            if (S[i]=='E'){
                E[i]=E[i-1]+1;
                W[i]=W[i-1];
            }
        }
    }
    
    ll ans=INF;
    rep(i,N){
        ll left=0;
        ll right=0;
        if (S[i]=='W'){
            if (i-1<0){
                left=0;
            }else{
                left=W[i-1];
            }
            right=cntE-E[i];//右にあるEの数
            ans=min(ans,left+right);
        }
            //cout << left <<" " << right << endl;
        if (S[i]=='E'){
            if (i-1<0){
                left=0;
            }else{
                left=W[i-1];
            }
            right=cntE-E[i];
            ans=min(ans,left+right);
            //cout << left <<" " << right << endl;
        }
        
    }
    cout << ans << endl;
}