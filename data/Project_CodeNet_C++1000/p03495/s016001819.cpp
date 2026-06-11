#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(ll i=(j);i<(n);++i)
#define rrep(i,n) for(int i=(n);i>=0;--i)
#define ssort(n) sort((n).begin(),(n).end())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define NG cout <<"UNRESTORABLE" << endl;
#define INF 10101010
int main()
{
    int N,K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i,N)cin >> a[i];

    vector<int> num(N+1);
    rep(i,N+1)num[i]=0;
    rep(i,N)num[a[i]]++;
    vector<int> rank(N+1);
    rep(i,N+1)rank[i]=INF;
    int j=0;
    rep(i,N+1){
        if(num[i]!=0){
            rank[j++]=num[i];
        }
    }
    ssort(rank);
    int l=0;
    int count=0;
    while(rank[l]!=INF){
        count++;l++;
    }
    int ans=0;
    
    rep(i,count-K){
        ans+=rank[i];
    }
    cout << ans << endl;
    

}