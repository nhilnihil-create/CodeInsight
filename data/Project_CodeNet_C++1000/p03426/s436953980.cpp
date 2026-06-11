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
    int h,w,d;cin>>h>>w>>d;
    vector<P> a(h*w+1);
    rep(i,h){
        rep(j,w){
            int A;cin>>A;
            a[A]={i+1,j+1};
        }
    }
    int sum[h*w+1];
    rep(i,d){
        sum[i+1]=0;
        for(int j =i+d+1;j<=h*w;j+=d){
            sum[j]=sum[j-d]+abs(a[j].first-a[j-d].first)+abs(a[j].second-a[j-d].second);
        }
    }
    int q;cin>>q;
    rep(_,q){
        int r,l;
        cin>>l>>r;
        cout<<sum[r]-sum[l]<<endl;
    }
}