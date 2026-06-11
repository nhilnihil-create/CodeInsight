#include<bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    int N; cin >> N;
    rep(i, 100000){
        if(i * i > N){
            cout << (i - 1)*(i - 1) << endl;
            return 0;
        }
    }
}