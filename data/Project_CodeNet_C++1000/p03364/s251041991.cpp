#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
int main(){
    int n; cin>>n;
    vector<string> s(n*2);
    rep(i,n){
        string u;cin>>u;
        s[i]=u+u;
        s[i+n]=s[i];
      //cout<<s[i][3]<<endl;
      //cout<<s[i+n]<<endl;
    }
    bool flag=true;
    int ans =0;
        rep(b,n){
            flag=true;
            rep(i,n){
                REP(j,i+1,n){
                    if(s[i][b+j]!=s[j][b+i]){
                        flag=false;
                        break;
                    }
                }
                if(flag==false){
                    break;
                }
            }
            if(flag==true){
                ans+=1;
            }
    }
    cout<<ans*n<<endl;
}