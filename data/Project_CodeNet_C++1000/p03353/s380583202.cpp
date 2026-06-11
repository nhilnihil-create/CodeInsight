#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string S;
    cin>>S;
    int K; cin>>K;
    vector<string> dic;
    int l = S.length();
    rep(i,min(5,l)){
        rep(j,l-i){
            if(find(dic.begin(),dic.end(),S.substr(j,i+1))==dic.end())dic.push_back(S.substr(j,i+1));
        }
    }
    sort(dic.begin(),dic.end());
    cout<<dic[K-1]<<endl;
    return 0;
}