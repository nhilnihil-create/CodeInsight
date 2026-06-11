#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define RFOR(i, a, b) for(int i = (b) - 1; i >= (a); i--)
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i < (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define ALL(i) (i).begin(),(i).end()
#define RALL(i) (i).begin(),(i).end(),greater<int>()
using namespace std;
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
template <typename T> void print(T x) { std::cout << x << '\n'; }

typedef long long ll;
#define TENNINE 1000000005
#define TENFIVE 200005
// #define int long long

string S;




signed main(){
    
    int K;
    cin>> S;
    int centor = S.size()/2 ;
    
    // int ans = K;    
    // bool end_flag = false;
    // FOR(k,K+1, S.size() ){
    //     char tmp = S[S.size()-k];
    //     FOR(i,S.size()-k,k){
    //         if(tmp != S[i])end_flag = true;
    //     }
    //     if(end_flag)break;
    //     ans = k;        
    // }
    char tmp = S[centor];
    int count = 0;
    int N = S.size();

    if(N%2 == 0){
        K = N/2;
        rep(i,N/2){
            if(S[centor+i] == S[centor-1-i])count++;
            else break;
        }
    }else{
        K = N/2+1;
        rep(i,N/2){
            if( tmp == S[centor+1+i] && S[centor-1-i] == S[centor+1+i]  )count++;
            else break;
        }
    }

    print(K+count);

    return 0;
}
