#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using Graph=vector<vector<int>>;
typedef long long ll;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    string S;
    int K;
    cin>>S>>K;
    int N=S.size();
    set<string>A;
    rep(i,N){
        int T=min(K,N-i+1);
        for(int j=1;j<=T;j++){
            A.insert(S.substr(i,j));
        }
    }
    int count=0;
    for (auto value : A){
        count++;
        if(count==K){
            cout<<value<<endl;
        }
    }
}
