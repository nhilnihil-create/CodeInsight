#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    int n;
    cin >> n;
    map<int,int> data;
    rep(i,0,n){
        int a;
        cin >> a;
        data[a]++;
    }
    int m;
    cin >> m;
    map<int,int> ans;
    rep(i,0,m){
        int a;
        cin >> a;
        ans[a]++;
    }
 
    for(auto x:ans){
        if(ans[x.first]>data[x.first]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    


    return 0;
}