#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll>Q;

ll ans[200010];

vector<int>g[200010];

int main(void){
    string s;
    cin>>s;
    int n = s.length();
    if(s[n-1]=='1'){
        cout<<-1<<endl;
        return 0;
    }
    if(s[0]!='1' || s[n-2]!='1'){
        cout<<-1<<endl;
        return 0;
    }
    if(n==2){
        if(s!="10")cout<<-1<<endl;
        else{
            cout<<1<<" "<<2<<endl;
        }
        return 0;
    }
    if(n==3){
        if(s!="110")cout<<-1<<endl;
        else{
            cout<<1<<" "<<2<<endl;
            cout<<2<<" "<<3<<endl;
        }
        return 0;
    }
    if(n%2==0){
        int m = n/2;
        for(int i=0;i<m-1;i++){
            if(s[i]!=s[n-2-i]){
                cout<<-1<<endl;
                return 0;
            }
        }
        int l = 0,r = 0;
        for(int i=m-1;i>=0;i--){
            if(l==0){
                if(s[i]=='1'){
                    l=i+1;
                    r=l+1;
                    g[l].push_back(r);
                }
            }
            else{
                if(s[i]=='1'){
                    g[i+1].push_back(l);
                    l=i+1;
                }
                else g[i+1].push_back(l);
            }
        }
        for(int i=r;i<n;i++)g[r].push_back(i+1);
    }
    else{
        int m=(n-1)/2;
        for(int i=0;i<m;i++){
            if(s[i]!=s[n-2-i]){
                cout<<-1<<endl;
                return 0;
            }
        }
        int l=0,r=0;
        for(int i=m-1;i>=0;i--){
            if(l==0){
                if(s[i]=='1'){
                    l=i+1;
                    r=l+1;
                    g[l].push_back(r);
                }
            }
            else{
                if(s[i]=='1'){
                    g[i+1].push_back(l);
                    l=i+1;
                }
                else g[i+1].push_back(l);
            }
        }
        for(int i=r;i<n;i++)g[r].push_back(i+1);
    }
    for(int i=1;i<=n;i++){
        if(g[i].size()){
            for(int j=0;j<g[i].size();j++){
                cout<<i<<" "<<g[i][j]<<endl;
            }
        }
    }
    return 0;
}