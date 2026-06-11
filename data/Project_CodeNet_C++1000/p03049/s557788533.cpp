#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i< (n);i++)
#define rep1(i,n) for(int i=1;i<= (n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const static ll MOD = (1e+9)+7;

int main(){
    int n;cin>>n;
    vector<string> S(n);rep(i,n)cin>>S[i];
    int B_A = 0,B=0,A=0;
    ll ans = 0;
    rep(i,n){
        rep(j,S[i].size()-1){
            if(S[i][j] == 'A'){
                if(S[i][j+1] == 'B')ans++;
            }
        }
    }
    rep(i,n){
        if(S[i][0] == 'B' && S[i][S[i].size()-1] == 'A'){
            B_A++;
        }else if(S[i][0] == 'B'){
            B++;
        }else if(S[i][S[i].size()-1] == 'A'){
            A++;
        }
    }
    if(B_A == 0){
        ans += min(A,B);
    }else{
        if(B>=2 && A>= 2){
            ans += 2+min(A-1,B-1);
        }else if(B>=1 && A>= 1){
            ans += 2;
        }else if(A == 0 && B == 0){
            ans += 0;
        }else{
            ans += 1;
        }
        if(B_A >= 2){
            ans += B_A -1;
        }
    }
    cout<<ans<<endl;
    return 0;
}