
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
    lli n;
    cin>>n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    vi ans;
    lli i=1;
    while(n!=0){
        lli now=pow(-2,i);
        if(abs(n)%abs(now)!=0){
            ans.push_back(1);
            n-=pow(-2,i-1);
        }
        else{
            ans.push_back(0);
        }
        i++;
    }
    reverse(all(ans));
    rep(i,ans.size()){
        cout<<ans[i];
    }
}