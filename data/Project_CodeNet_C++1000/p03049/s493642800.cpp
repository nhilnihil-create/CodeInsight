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
const int mod=1e9+7;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,x,n) for (int i= x;i<n;i++)
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
using vp =vector<pair<int,int>>;

typedef pair<int,int> P;
string s;
int k;
ll INF = 10000000000000000;

int c(string S){
    int n = S.size();
    int count = 0;
    rep(i,n-1){
        if(S.substr(i,2)=="AB") count++;
    }
    return count;
}

int jAB(string S){
    int n = S.size();
    int j=0;
    if(S[0]=='B') j+=1;
    if(S[n-1]=='A') j+=2;
    return j;
}

int main(){
    int N;
    cin >>N;
    vector<string> S(N);
    int ans=0;
    vi AB(4,0);
    rep(i,N){
        cin >>S[i];
        ans += c(S[i]); 
    }
    rep(i,N){
        int n=jAB(S[i]);
        AB[n]++;
    }
    if(AB[1]==0&&AB[2]==0) ans += max(0,AB[3]-1);
    else if(AB[3]==0) ans += min(AB[1],AB[2]);
    else if(AB[1]==AB[2]) ans+=AB[3]+AB[1];
    else ans += AB[3]+min(AB[1],AB[2]);
    cout <<ans<<endl;
}