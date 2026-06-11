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
	str S,T;cin>>S>>T;
    ll m=S.size()-1;
    rep0(i,S.size()){
        char hold=S[0];
        rep0(j,m+1){
            if(j!=m)S[j]=S[j+1];
            else S[j]=hold;
        }
        if(S==T){cout<<"Yes"<<endl;return 0;}
    }
    cout<<"No"<<endl;
}

