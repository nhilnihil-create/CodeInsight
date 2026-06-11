#include <bits/stdc++.h>
#include<cmath>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = (1LL << 60LL);

int N;
vector<string>W(N);
vector<string>already(N);
bool cc(){
    already.push_back(W.at(0));
    for(int i=1;i<N;i++){
    
        rep(j,already.size()){
            if(already.at(j)==W.at(i))return false;
        }

        already.push_back(W.at(i));

        if(!(W[i][0]==W[i-1][W[i-1].size()-1])){
            return false;
        }
    }

    return true;
}

int main(){
    cin>>N;
    W.resize(N);
    already.resize(N);
    rep(i,N)cin>>W.at(i);

    if(cc())cout<<"Yes";
    else cout<<"No";
}