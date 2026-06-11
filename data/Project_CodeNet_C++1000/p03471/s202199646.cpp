#include <bits/stdc++.h>
 
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
// cin.eof() 入力個数の問題
 
int main() {
    int n,y;
    cin>>n>>y;
    rep(i,n+1){
        rep(j,n+1){
            int s=y-1000*i-5000*j;
            if(s>=0&&s%10000==0&&s/10000==n-i-j){
                cout<<s/10000<<" "<<j<<" "<<i<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
    return 0;
}
