#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

bool solve(){
    int A,B,C,D;
    cin>>A>>B>>C>>D;

    if(B>D)return false;
    if(B>A)return false;

    if(C>=B)return true;

    A%=B;

    int g=gcd(B,D);

    int x=A+(B-1-A)/g*g;
    if(x>C)return false;
    return true;
}

signed main(){
    int T;cin>>T;
    while(T--){
        cout<<(solve()?"Yes":"No")<<endl;
    }
    return 0;
}
