#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main(){
    ll N; cin>>N;
    vector<ll> A(N); rep(i,N)cin>>A.at(i);
    ll res = 0;
    int e = 0;//end
    ll sum = 0;
    for(int s = 0; s < N; s++){
        while(e < N && (sum ^ A.at(e)) == (sum + A.at(e))){
            sum += A.at(e);
            e++;
        }
        res += e - s;
        if(s == e) e++;
        else{
            sum -= A.at(s);
        }
    }
    cout<<res<<endl;
}
