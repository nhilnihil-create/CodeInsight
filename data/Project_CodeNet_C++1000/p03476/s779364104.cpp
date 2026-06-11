
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    set<lli> prime;
    prime.insert(2);
    for(lli i=3;i<=100000;i++){
        lli ic=i;
        for(auto j:prime){
            if(j*j>ic&&ic!=1){
                prime.insert(ic);
                break;
            }
            else{
                if(ic%j==0){
                    while(ic%j==0) ic/=j;
                }
            }
        }
    }
    vi cnt(1000001,0);
    for(auto v:prime){
        if(prime.count((v+1)/2)) cnt[v]+=1;
    }
    for(lli i=1;i<cnt.size();i++) cnt[i]+=cnt[i-1];
    lli q;
    cin>>q;
    rep(i,q){
        lli l,r,ans=0;
        cin>>l>>r;
        ans=cnt[r]-cnt[l-1];
        out(ans);
    }
}