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
    vector<int> data(n+1);
    data[0]=0;
    rep(i,0,n){
        cin >> data[i+1];
    }
    int ans=0;
    rep(i,0,n){
        if(data[i+1]>data[i]){
            ans += data[i+1]-data[i];
        }
    }
    cout<<ans<<endl;

  return 0;
}