#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int k;
    cin>>k;
    vector<ll> a(k);
    rep(i,k) cin>>a[i];

    ll min_n=2,max_n=2;
    for(int i=k-1;i>=0;i--){
        ll min_num=((min_n+a[i]-1)/a[i])*a[i];
        ll max_num=(max_n/a[i])*a[i]+a[i]-1;
        if(min_num>max_n || max_num<min_n){
            cout<<-1<<endl;
            return 0;
        }
        min_n=min_num;
        max_n=max_num;
    }

    cout<<min_n<<" "<<max_n<<endl;
}