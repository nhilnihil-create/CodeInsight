#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end() 
#define rep(i, K, N)  for(int i = K; i < N; i++)
#define ll long long int
using namespace std;
int main() {
ll N, Q;cin >> N >> Q;
string S;cin >> S;
vector<pair<ll, ll>> range(Q);
vector<ll> V;

rep(i, 0, Q)cin >> range[i].first >> range[i].second;

rep(i, 1, N){
if(S[i - 1] == 'A' && S[i] == 'C')V.push_back(i - 1);
}

if(V.empty()){
rep(i, 0, Q)cout << 0 << endl;
exit(0);
}

for(auto x : range){
ll l = 0, r  = V.size() - 1;

if(x.second - 1 <= V[0] || x.first - 1 >= V[r] + 1){
cout << 0 << endl;continue;}

    while(V[l] < x.first - 1){
    l++;
    }

    while(V[r] + 1 > x.second - 1){
    r--;
    }

cout <<  r - l + 1 << endl;

}


}