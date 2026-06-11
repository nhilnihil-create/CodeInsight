#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
signed main(){
    int T; cin>>T;
    rep(_,0,T){
        int A,B,C,D; cin>>A>>B>>C>>D;
        if(D<B){
            cout<<"No"<<endl;
            continue;
        }
        int Y=__gcd(B,D);
        int Z=A-max(0ll,(A-C-1)/Y*Y);
        if(Z<B) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
}