#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
int main(){
    int cnt=0;
    vector<pair<int,int>> ans;
    
    int n;
    cin>>n;
    vector<int> a(n);
    int max=-1,max_index=-1;
    int min=INF,min_index=-1;
    rep(i,n){
        cin>>a[i];
        if(a[i]<0 && a[i]<min){
            min=a[i];
            min_index=i;
        }
        else if(a[i]>=0 && a[i]>max){
            max=a[i];
            max_index=i;
        }
    }
    
    if(max!=-1 && min!=INF){
        if(abs(max)>=abs(min)){
            rep(i,n){
                if(i==max_index) continue;
                if(a[i]<0){
                    a[i]+=max;
                    ans.emplace_back(max_index,i);
                    cnt++;
                }
            }
        }
        else{
            rep(i,n){
                if(i==min_index) continue;
                if(a[i]>=0){
                    a[i]+=min;
                    ans.emplace_back(min_index,i);
                    cnt++;
                }
            }
        }
    }
    
    if(a[0]>=0){
        rep(i,n-1){
            if(a[i]>a[i+1]){
                a[i+1]+=a[i];
                ans.emplace_back(i,i+1);
                cnt++;
            }
        }
    }
    else{
        rrep(i,n-1){
            if(a[i]>a[i+1]){
                a[i]+=a[i+1];
                ans.emplace_back(i+1,i);
                cnt++;
            }
        }
    }
    
    
    cout<<cnt<<endl;
    for(auto p:ans){
        int x,y;
        tie(x,y)=p;
        cout<<x+1<<" "<<y+1<<endl;
    }
    
    //for(int x:a) cout<<x<<endl;
}

