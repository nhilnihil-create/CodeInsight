#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007

int main() {
    vector<int>ab(4);
    rep(i,6){
        int a;cin>>a;
        ab[a-1]++;
    }

    bool jdg=true;
    rep(i,4){
        if(ab[i]==0||ab[i]==3){
            cout<<"NO"<<endl;
            jdg=false;
            break;
        }
    }
    if(jdg){
        cout<<"YES"<<endl;
    }

}
