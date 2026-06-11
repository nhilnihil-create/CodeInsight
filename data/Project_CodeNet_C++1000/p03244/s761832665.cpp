#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;

int main(){
    int n ;cin>>n;
    int v[n];
    rep(i,n)cin>>v[i];
    vi e(100005.0),p(100005,0);
    rep(i,n){
        if(i%2==0){
            e[v[i]]++;
        }
        else p[v[i]]++;
    }
    int em=max_element(been(e))-e.begin(),pm=max_element(been(p))-p.begin();
    if(em==pm){
        int ee =e[em],pp=p[pm];
        e[em]=0;p[pm]=0;
        em=max_element(been(e))-e.begin(),pm=max_element(been(p))-p.begin();
        cout<<min(n-ee-p[pm],n-e[em]-pp)<<endl;
    }
    else{
        cout<<n-e[em]-p[pm]<<endl;
    }
}