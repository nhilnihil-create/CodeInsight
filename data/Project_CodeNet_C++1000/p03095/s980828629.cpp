#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N;
    string S;
    cin >> N >> S;
    map<char,ll> mp;
    rep(i,N){
        mp[S[i]]++;
    }
    ll cnt = 1;
    for(auto& e:mp){
        cnt *= (e.second+1);
        cnt %= mo;
    }
    cnt--;
    cnt %= mo;
    cout <<cnt<<endl;
}
