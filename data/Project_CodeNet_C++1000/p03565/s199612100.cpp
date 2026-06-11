#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    string s,t;
    cin>>s>>t;

    int n=s.size();
    int m=t.size();
    if(n<m){
        cout<<"UNRESTORABLE"<<endl;
        return 0;
    }

    for(int i=n-m;i>=0;i--){
        bool ok=true;
        for(int j=0;j<m;j++){
            if(s[i+j]=='?') continue;
            if(s[i+j]!=t[j]) ok=false;
        }
        if(ok){
            for(int j=0;j<m;j++){
                if(s[i+j]=='?') s[i+j]=t[j];
            }
            rep(i,n){
                if(s[i]=='?') s[i]='a';
            }
            cout<<s<<endl;
            return 0;
        }
    }
    cout<<"UNRESTORABLE"<<endl;

}
