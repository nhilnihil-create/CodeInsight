#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    string  s;
    cin>>s;
    if(s=="A") cout<<"T"<<endl;
    else if(s=="T") cout<<"A"<<endl;
    else if(s=="C") cout<<"G"<<endl;
    else cout<<"C"<<endl;
    return 0;
}