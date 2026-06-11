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
    string s;
    cin>>s;
    int a[4];
    rep(i,4)a[i]=s[i]-'0';
    rep(i,8){
        int ans=a[0];
        for(int j=2;j>=0;--j){
            if((i>>j)&1){
                ans+=a[3-j];
            }else{
                ans-=a[3-j];
            }
        }
        if(ans==7){
            cout<<a[0];
            for(int k=2;k>=0;--k){
                if((i>>k)&1){
                    cout<<"+"<<a[3-k];
                }else{
                    cout<<"-"<<a[3-k];
                }
            }
            cout<<"=7"<<endl;
            return 0;
        }
    }
}
