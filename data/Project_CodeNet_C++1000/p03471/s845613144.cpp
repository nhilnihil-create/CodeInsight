#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using graph=vector<vector<int>>;
using field=vector<string>;
using p =pair<int,int>;
const ll mod=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int main(){
    ll n,Y;
    cin>>n>>Y;
    for(int x=0;x<=n;++x){
        for(int y=0;y<=n-x;++y){
            int sum=x*10000+y*5000+(n-x-y)*1000;
            if(sum==Y){
                cout<<x<<" "<<y<<" "<<n-x-y<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
}