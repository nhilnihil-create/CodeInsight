#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    string S; cin>>S;
    int a[4];
    rep(i,4){
        a[i]=S[i]-'0';
    }    
    rep(bit,1<<3){
        int ans=a[0];
        char c[3]={'+','+','+'};
        rep(i,3){
            if(bit&(1<<i)){
                ans+=a[i+1];
            }
            else {
                ans-=a[i+1];
                c[i]='-';
            }
        }
        if(ans==7){
            rep(i,3){
                cout<<S[i]<<c[i];
            }
            cout<<S[3]<<"=7"<<endl;
            return 0;
        }
    }
}