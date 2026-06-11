#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include <bitset>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,x,n) for (int i= x;i<n;i++)
#define all(v) v.begin(), v.end()
#define nepe(v) next_permutation(all(v))
using ll = long long;
using vi = vector<int>; 
using vvi = vector<vi>;

typedef pair<int,int> P;
string s;
int k;
ll INF = 10000000000000000;

int main(){
    ll N,M;
    cin >> N>> M;
    vector<P> ask(M);
    rep(i,M){
        cin >>ask[i].second>>ask[i].first;     
    }
    sort(all(ask));

    ll ans=1;
    ll end=ask[0].first-1; 
    rep2(i,1,M){
        if(ask[i].second > end){
            ans++;
            end = ask[i].first-1;
        }

    }
    cout <<ans<<endl;

}