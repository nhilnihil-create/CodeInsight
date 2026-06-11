#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<int> ar;
    if(S[0]=='0'){
        ar.push_back(0);
    }
    char bf = S[0];
    int d = 0;
    rep(i,N){
        if(S[i]!=bf){
            ar.push_back(d);
            bf = S[i];
            d=1;
        }else{
            d++;
            if(i==N-1){
                ar.push_back(d);
            }
        }
    }
    if(S[N-1]=='0'){
        ar.push_back(0);
    }
    vector<int> Sum(ar.size()+1);
    rep(i,ar.size()){
        Sum[i+1] = Sum[i] + ar[i];
    }
    // 0...0の塊を反転させるとその左右含めた長さ分つながる
    int ans = 0;
    for(int l=0;l<Sum.size();l+=2){ // l:1...1の始まり
        int r = min(l+2*K+1,(int)Sum.size()-1);
        ans = max(ans,Sum[r]-Sum[l]);
    }
    cout << ans << endl;
    return 0;
}