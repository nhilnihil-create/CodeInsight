#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2003,INF=10000;

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    int T;cin>>T;
    for(int i=0;i<T;i++){
        ll A,B,C,D;cin>>A>>B>>C>>D;
        bool flag=true;
        if(A<B) flag=false;
        else if(A%B>C) flag=false;
        else if(B>D) flag=false;
        else if(B<C) flag=true;
        else{
            if(D%B==0){
                flag=true;
            }else{
                ll E=gcd(B,D);
                ll X=A%B;
                ll M=(B-X-1)/E;
                
                if(X+M*E>C) flag=false;
                else flag=true;
            }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
