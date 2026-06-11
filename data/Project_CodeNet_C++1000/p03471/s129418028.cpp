#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N,Y;
    cin>>N>>Y;
    int ans[3]={-1,-1,-1};
    rep(i,N+1){
        rep(j,N-i+1){
            if((Y-1000*i-5000*j)%10000==0&&(Y-1000*i-5000*j)/10000==N-i-j){
                ans[0]=i;
                ans[1]=j;
                ans[2]=N-i-j;
                break;
            }
        }
    }
    cout<<ans[2]<<" "<<ans[1]<<" "<<ans[0]<<endl;
    return 0;
}