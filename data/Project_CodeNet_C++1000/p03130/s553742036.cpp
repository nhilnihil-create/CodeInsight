#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int C[5];
int main(void){
    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;
    C[a]++; C[b]++; C[c]++; C[d]++; C[e]++; C[f]++;
    for(int i=1;i<=4;i++){
        if(C[i]>=3){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    
}
