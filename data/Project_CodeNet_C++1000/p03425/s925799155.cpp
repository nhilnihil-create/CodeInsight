#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n + 1); i++)
// vector<vector<int>> A(3, vector<int>(4));
int main() {
    int N;
    cin>>N;
    vector<string>S(N);
    ll cnM=0;
    ll cnA=0;
    ll cnR=0;
    ll cnC=0;
    ll cnH=0;
    rep(i,N){
        cin>>S[i];
        if(S[i][0]=='M'){
            cnM++;
        }
        else if(S[i][0]=='A'){
            cnA++;
        }
        else if(S[i][0]=='R'){
            cnR++;
        }
        else if(S[i][0]=='C'){
            cnC++;
        }
        else if(S[i][0]=='H'){
            cnH++;
        }
    }
    ll ans=0;
    ans+=cnM*cnA*(cnR+cnC+cnH)+(cnM+cnA+cnR)*(cnC*cnH)+(cnM+cnA)*cnR*(cnC+cnH);
    cout<<ans<<endl;
}
