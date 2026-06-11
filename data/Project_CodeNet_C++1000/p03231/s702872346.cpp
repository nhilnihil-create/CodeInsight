#define _LIBCPP_DEBUG 0
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef vector<int> vi;
typedef long long ll;

ll GCD(ll a,ll b){

    if(a>b){

        return GCD(b,a);

    }

    else{

    ll r=b%a;

    while(r!=0){

        b=a;

        a=r;

        r=b%a;

    }

    return a;

    }

}

int main(){
    
    ll N,M;cin>>N>>M;
    string s,t;cin>>s>>t;
    ll gcd=GCD(N,M);
    ll lcm=N*M/gcd;
    if(gcd==1&&s.at(0)!=t.at(0)){
        cout<<-1<<endl;
        return 0;
    }
    else{
        int ok=1;
        rep(i,0,gcd){
            if(s.at(i*(N/gcd))!=t.at(i*(M/gcd)))ok=0;
        }
        if(ok==0){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<lcm<<endl;
}




