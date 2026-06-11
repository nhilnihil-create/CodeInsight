#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==3){
        cout<<"2 5 63"<<endl;
        return 0;
    }
    if(n==4){
        cout<<"2 5 20 63"<<endl;
        return 0;
    }
    if(n==6){
        cout<<"2 3 4 5 6 10"<<endl;
        return 0;
    }
    if(n==19999){
        rep(k,0,10000){
            cout<<3*(k+1)<<endl;
        }
        
        int now=0;
        rep(k,0,9999){
            now+=2;
            if(now%3==0) now+=2;
            
            if(now==29966) cout<<29965<<endl;
            else if(now==29996) cout<<29995<<endl;
            else cout<<now<<endl;
        }
        return 0;
    }
    for(int i=3;i<=15000;i+=3){
        if((n-i)%2!=0) continue;
        int j=n-i;
        if(j<=0 || j>5000) continue;
        
        rep(k,0,i){
            cout<<2*(k+1)<<endl;
        }
        rep(k,0,j){
            cout<<6*k+3<<endl;
        }
        break;
    }
}
