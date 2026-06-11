#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;cin>>n;
    if(n==3){
        cout<<2<<' '<<5<<' '<<63<<endl;
        return 0;
    }
    if(n==4){
        cout<<2<<' '<<5<<' '<<20<<' '<<63<<endl;
        return 0;
    }
    ll c2=8,c3=15,c6=12;
    cout<<2<<' '<<4<<' '<<6<<' '<<3<<' '<<9<<' ';
    n-=5;
    while(n&&c2<=30000){
        if(n>=2){
            n-=2;
            cout<<c2<<' '<<c2+2<<' ';
            c2+=6;
        }else{
            break;
        }
    }
    while(n&&c3<=30000){
        if(n>=2){
            n-=2;
            cout<<c3<<' '<<c3+6<<' ';
            c3+=12;
        }else{
            break;
        }
    }
    while(n){
        cout<<c6<<' ';
        n--;
        c6+=6;
    }
}