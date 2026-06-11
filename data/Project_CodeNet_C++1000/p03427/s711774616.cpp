#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    string N;
    cin>>N;
    int cnt=N.size();
    bool all9=true;
    rep2(i,1,cnt){
        if(N[i]!='9'){
            all9=false;
        }
    }
    int ans=0;
    if(all9){
        ans=N[0]-'0'+(cnt-1)*9;
    }else{
        ans=N[0]-'0'-1+(cnt-1)*9;
    }
    cout << ans << endl;
    
    return 0;
}