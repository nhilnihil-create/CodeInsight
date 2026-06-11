#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
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
    ll N;
    cin>>N;
    vector<pair<int,int>>R(N);
    vector<pair<int,int>>B(N);
    vector<int>uselist(N,0);
    rep(i,N){
        cin>>R[i].second>>R[i].first;
    }
    rep(i,N){
        cin>>B[i].first>>B[i].second;
    }
    sort(R.begin(),R.end());
    reverse(R.begin(),R.end());
    sort(B.begin(),B.end());
    int cnt=0;
    rep(i,N){
        rep(j,N){
            if(R[j].first<B[i].second&&R[j].second<B[i].first&&uselist[j]==0){
                uselist[j]=1;
                cnt++;
                break;
            }
        }
    }
    cout<<cnt<<endl;
}
    