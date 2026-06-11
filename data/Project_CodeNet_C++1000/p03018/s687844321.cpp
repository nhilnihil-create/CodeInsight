#include <bits/stdc++.h>
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
    string s;cin>>s;
    int n =s.length();
    ll ans =0;
    bool f=false;
    string ns;
    rep(i,n){
        if(i==n-1){
            ns.push_back(s[i]);
        }
        else{
            if(s[i]=='B'&&s[i+1]=='C'){
                i++;
                ns.push_back('D');
            }
            else ns.push_back(s[i]);
        }
    }
    n =ns.length();
    //reverse(been(ns));
    int a=0;
    rep(i,n){
        if(ns[i]=='D'){
            ans+=a;
        }
        else if(ns[i]=='A'){
            a++;
        }
        else{
            a=0;
        }
    }
    cout<<ans<<endl;
}
