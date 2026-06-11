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
    ll A,B,C,K;
    cin>>A>>B>>C>>K;
    if(K%2==1&&abs(A-B)<=1000000000000000000){
        cout<<B-A<<endl; return 0;
    }
    if(abs(A-B)>1000000000000000000){
        cout<<"Unfair"<<endl; return 0;
    }
    else if(K%2==0){
        cout<<A-B<<endl;
    }
}