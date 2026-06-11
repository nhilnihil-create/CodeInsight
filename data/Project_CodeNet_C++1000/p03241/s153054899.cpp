#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
using namespace std;
int main(void){
    int n;ll m;cin>>n>>m;
    for(int i=m/n+1;i>=1;i--){
        if(!(m%i)&&m/i>=n){
            cout<<i<<endl;
            return 0;
        }
    }
}
