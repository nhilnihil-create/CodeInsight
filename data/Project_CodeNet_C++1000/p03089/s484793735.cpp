#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
const int mod= 1e+9+7;

int main() {
    int N; cin>>N;
    vector<int>b(N);
    rep(i,N)cin>>b[i];
    int a=N;
    bool judge;
    vector<int>ans(N);
    rep(i,N){
        judge=true;
        rep(j,a){
            if(b[a-1-j]==a-j){
                ans[i]=a-j;
                b.erase(b.begin()+a-1-j);
                a--;
                //cout<<a-j<<" "<<a<<endl;
                judge=false;
                break;
            }
        }
        if(judge){
            cout<<-1<<endl;
            return 0;
        }
        }
        reverse(ans.begin(),ans.end());
        rep(i,N)cout<<ans[i]<<endl;
    }