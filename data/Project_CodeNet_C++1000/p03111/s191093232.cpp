#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
const int inf=1e+9;
int main(void){
    int n,a,b,c;cin>>n>>a>>b>>c;
    vector<int> l(n);
    rep(i,n) cin>>l[i];
    int res=inf;
    for(int i=0;i<(1<<16);i++){
        int na=0,nb=0,nc=0,tmp=i;
        int now=0;
        rep(j,n){
            if(tmp%4==1){
                if(na!=0)now+=10;
                na+=l[j];
            }
            else if(tmp%4==2){
                if(nb!=0)now+=10;
                nb+=l[j];
            }
            else if(tmp%4==3){
                if(nc!=0)now+=10;
                nc+=l[j];
            }
            tmp/=4;
        }
        if(na==0||nb==0||nc==0)continue;
        int A=a-na;
        int B=b-nb;
        int C=c-nc;
        if(A<0)A*=-1;
        if(B<0)B*=-1;
        if(C<0)C*=-1;
        res=min(res,A+B+C+now);
    }
    cout<<res<<endl;
}