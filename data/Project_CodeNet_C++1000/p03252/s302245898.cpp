#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int f[26][26];

int main(){
    string s,t;
    cin>>s>>t;

    int n=s.size();
    rep(i,n){
        int a=s[i]-'a';
        int b=t[i]-'a';
        f[a][b]=1;
    }

    rep(i,26){
        int cn=0;
        rep(j,26){
            if(f[i][j]) cn++;
        }
        if(2<=cn){
            cout<<"No"<<endl;
            return 0;
        }
    }

    rep(j,26){
        int cn=0;
        rep(i,26){
            if(f[i][j]) cn++;
        }
        if(2<=cn){
            cout<<"No"<<endl;
            return 0;
        }
    }


    cout<<"Yes"<<endl;
}
