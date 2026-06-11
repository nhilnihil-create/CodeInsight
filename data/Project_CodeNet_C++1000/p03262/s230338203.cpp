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
int gcd(long long int x,long long int y){
    if(y==0) return x;
    return gcd(y,x%y);

}
int main(){
    lli n,x,ans;
    cin>>n>>x;
    rep(i,n){
        lli xi;
        cin>>xi;
        xi=abs(xi-x);
        if(i==0){
            ans=xi;
        }
        else{
            ans=gcd(xi,ans);
        }
    }
    out(ans);
}