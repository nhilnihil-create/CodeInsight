#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    string S;
    cin>>S;
    int y,m,d;
    y=(S.at(0)-'0')*1000+(S.at(1)-'0')*100+(S.at(2)-'0')*10+(S.at(3)-'0');
    m=(S.at(5)-'0')*10+(S.at(6)-'0');
    d=(S.at(8)-'0')*10+(S.at(9)-'0');
    if(make_tuple(y,m,d)<=make_tuple(2019,4,30)){
        cout<<"Heisei"<<endl;
    }
    else cout<<"TBD"<<endl;
}