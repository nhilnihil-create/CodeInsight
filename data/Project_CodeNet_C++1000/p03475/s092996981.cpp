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
    vvi rec(n,vi(3,0));
    vi ans(n+1,0);
    ans[n]=0;
    rep(i,n-1){
        cin>>rec[i+1][0]>>rec[i+1][1]>>rec[i+1][2];
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i;j<=n-1;j++) ans[j]=0;
        for(int j=i;j<=n-1;j++){
            if(j==i){
                ans[i]=rec[i][1]+rec[i][0];
            }
            else{
                if(ans[i]<=rec[j][1]){
                    ans[i]=rec[j][1]+rec[j][0];
                }
                else{
                    if(ans[i]%rec[j][2]==0){
                        ans[i]+=rec[j][0];
                    }
                    else{
                        ans[i]+=rec[j][2]-ans[i]%rec[j][2]+rec[j][0];
                    }
                }
            }
        }
        out(ans[i]);
    }
out(ans[n]);

}