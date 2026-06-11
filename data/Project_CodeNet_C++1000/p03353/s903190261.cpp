#include <bits/stdc++.h>
#include <cmath>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
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
    string s;
    int k;
    cin>>s>>k;
    int n=s.length();
    set<string> a;
    rep(j,k+1){
        if(j==0)continue;
        rep(i,n-j+1){
            a.insert(s.substr(i,j));
        }
    }
    vector<string>ans;
    for(auto x:a){
        ans.push_back(x);
    }
    cout<<ans[k-1]<<endl;

}
