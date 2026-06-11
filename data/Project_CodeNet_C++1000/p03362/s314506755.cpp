#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
#define MAX 55555
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    int N; cin>>N;
    vector<ll> P(MAX+1,-1);
    vector<int> R;
    for(int i = 2; i <= MAX; i++){
        if(P.at(i)!=-1)continue;
        else R.push_back(i);
        for(int j = 1; j*i <= MAX; j++){
            P.at(j*i) = i;
        }
    }
    vector<set<int>> res(5);
    for(auto i:R){
        int m = i%5;
        res.at(m).insert(i);
    }
    auto iter = res.at(1).begin();
    rep(i,N){
        cout<<*iter<<endl;
        iter++;
    }
}
