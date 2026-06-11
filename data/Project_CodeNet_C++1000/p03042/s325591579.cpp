#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pb push_back
#define fi first
#define se second
#define ld long double
#define vi vector<vector<ll> >
using namespace std;
const int MOD=1000000007;
const int MOD2=15000007;
const ll MAX=9187201950435737471;
const int N=100005;
const int INF=1e17;
const long double PI=acos(-1);



void solve(int T){
   string s;
   cin>>s;
   int n=(s[0]-'0')*10 + (s[1]-'0'),r=(s[2]-'0')*10 + (s[3]-'0');
    if(n>12 && r<=12 && r>0){
        cout<<"YYMM\n";
    }
    else if(n<=12 && n>0 && r>12){
        cout<<"MMYY\n";
    }
    else if(n<=12 && r==0 && n>0){
        cout<<"MMYY\n";
    }
    else if(n==0 && r<=12 && r>0){
        cout<<"YYMM\n";
    }
    else if(n<=12 && r<=12 && n>0 && r>0){
        cout<<"AMBIGUOUS\n";
    }
    else {
        cout<<"NA\n";
    }
}

int main() {
    fastio
    int T=1;
    //cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
        //if(i<T)cout<<"\n";
    }
    return 0;
}



