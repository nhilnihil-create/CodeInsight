#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A,B;
    char field[110][110];
    cin>>A>>B;
    A--;B--;
    rep(i,50){
        rep(j,100){
            field[i][j]='.';
        }
    }
    rep2(i,50,100){
        rep(j,100){
            field[i][j]='#';
        }
    }
    for(ll i=0;i<50;i+=2){
        for(ll j=0;j<100;j+=2){
            if(B>0){
                field[i][j]='#';
                B--;
            }
        }
    }
    for(ll i=51;i<100;i+=2){
        for(ll j=0;j<100;j+=2){
            if(A>0){
                field[i][j]='.';
                A--;
            }
        }
    }
    cout<<100<<" "<<100<<endl;
    rep(i,100){
        rep(j,100){
            cout<<field[i][j];
        }
        cout<<endl;
    }
    return 0;
}