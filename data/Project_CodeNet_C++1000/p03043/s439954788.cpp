#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n,k;
    cin>>n>>k;

    double ans=1/(double)n;
    double tmp=0;
    for(int i=1;i<=n;i++){
        int x=i;
        int cnt=1;
        if(i>=k) cnt=0; 
        while(1){
            if(x*2>=k) break;
            cnt++;
            x*=2;
        }
        //cout<<cnt<<endl;
        double add=1/(double)pow(2,cnt);
        //cout<<add<<endl;
        tmp+=add;
    }
    //cout<<ans<<endl;
    ans*=tmp;
    cout<<fixed<<setprecision(10)<<ans<<endl;
}