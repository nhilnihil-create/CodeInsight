#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    string S;
    cin>>S;
    rep(i,0,2){
        string p;
        if(i==1) p+="A";
        p+="KIH";
        rep(j,0,2){
            string q;
            if(j==1) q+='A';
            q+='B';
            rep(k,0,2){
                string r;
                if(k==1) r+='A';
                r+='R';
                rep(l,0,2){
                    string s;
                    if(l==1) s+='A';
                    if(p+q+r+s==S){
                        cout<<"YES"<<endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    cout<<"NO"<<endl;
}
