#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int N,K;
    cin>>N>>K;
    string S;cin>>S;
    if(S.at(K-1)=='A'){
        S.at(K-1)='a';
    }else if(S.at(K-1)=='B'){
        S.at(K-1)='b';
    }else{
        S.at(K-1)='c';
    }
    cout<<S<<endl;
    
}
