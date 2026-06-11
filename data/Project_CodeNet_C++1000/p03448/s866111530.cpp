#include <bits/stdc++.h>
using namespace std;
#define rep0(i, n) for (long long i = 0; i < (long long)(n); i++)
#define rep1(i,n) for(long long i=1;i<=(long long)(n);i++)
#define all(v) v.begin(),v.end()
#define Sort(v) sort(all(v))
#define Reverse(v) reverse(all(v))
#define Rsort(v) sort(all(v),greater)
#define pub(v) push_back(v)
#define pob(v) pop_back(v)
typedef long long ll;
typedef vector<ll> vel;
typedef vector<vector<ll>> vel2d;
typedef string str;
typedef pair<ll,ll> pal;
typedef vector<str> ves;
typedef vector<char> vech;

int main() {
    ll A,B,C,X,sum,cnt=0; cin>>A>>B>>C>>X;
    for(ll i=0;i<=A;i++){
        for(ll j=0;j<=B;j++){
            for(ll k=0;k<=C;k++){
                sum=500*i+100*j+50*k;
                if(sum==X){
                    cnt++;
                }
            }
        }
    }
    cout<<cnt<<endl;
}
