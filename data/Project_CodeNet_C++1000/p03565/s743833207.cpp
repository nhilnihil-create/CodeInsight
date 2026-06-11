#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<int,int>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string S,T;
    cin>>S>>T;
    int N = S.size(),M = T.size();
    bool can = false;
    int p=0;
    for(int i = N-M;i>=0;i--){
        bool ok = true;
        rep(j,M){
            if(S[i+j]!=T[j]&&S[i+j]!='?'){
                ok = false;
            }
        }
        if(ok){
            p=i;
          	can = true;
            break;
        }
    }
    if(!can) cout<<"UNRESTORABLE"<<endl;
    else{
        rep(i,N){
            if(i<p||i>=p+M){
                if(S[i]!='?') cout<<S[i];
                else cout<<'a';
            }
            else {
                cout<<T[i-p];
            }
        }
        cout<<endl;
    }
}