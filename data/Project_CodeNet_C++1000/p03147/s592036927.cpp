#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define INF (1e9)
#define rep(i,n) for(int i=0;i<(int)n;i++)

vector<int> dat;
int n;

int main(){
    int ans=0;
    cin>>n;
    dat=vector<int>(n);
    rep(i,n) cin>>dat[i];
    while(dat.size()){
        ans++;
        rep(i,dat.size()){
            if(dat[i]!=0){
                dat[i]--;
            }
            else if(i==0){
                dat.erase(dat.begin());
                i--;
                ans--;
                break;
            }
            else{
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}