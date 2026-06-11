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
    const str s="keyence";
    str t; cin>>t;
    if(t==s){puts("YES");return 0;}
    else{
        ll n=t.size();
        rep0(i,n){
            for(ll j=i;j<n;j++){
                str S="";
                rep0(k,n){
                    if(i<=k&&k<=j){
                        continue;
                    }
                    else{
                        S+=t[k];
                    }
                }
                //cout<<S<<endl;
                if(S==s){puts("YES");return 0;}
            }
        }
    }
    puts("NO");
}
