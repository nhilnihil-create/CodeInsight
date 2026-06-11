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
const long long mod=1e9+7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define rep2(i,x,n) for(int i= x;i<n;i++)
#define all(v) v.begin(), v.end()
#define nepe(v) next_permutation(all(v))
#define F first 
#define S second
#define PB push_back 
#define MP make_pair
using ll = long long;
using vi = vector<int>; 
using vvi = vector<vi>;
using vl=vector<long long>;
using vvl = vector<vl>;
using vp =vector<pair<int,int>>;

typedef pair<int,int> P;
string s;
int k; 
ll INF = 10000000000000000;



int main(){
    int N;
    string S;
    cin >>N>>S;
    vi abc(26,0);
    rep(i,N){
        abc[S[i]-'a']++;
    }
    ll ans=1;
    rep(i,26){
        ans *= abc[i]+1;
        ans %= mod;
    }
    cout <<ans-1<<endl;
}