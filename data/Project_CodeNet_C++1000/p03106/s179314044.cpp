#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int a,b,k;
    cin>>a>>b>>k;
    for(int i=100;i>0;--i){
        if(a%i==0 && b%i==0) k--;
        if(k==0){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}