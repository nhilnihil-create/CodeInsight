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
    vector<ll> data(n);
    int minus_cnt = 0;
    ll sum = 0;
    rep(i,0,n){
        ll num;
        cin >>num;
        data[i]=abs(num);
        if(num<-1){
            minus_cnt++;
        }
        sum += abs(data[i]);
    }
    sort(data.begin(),data.end());
    if(minus_cnt%2==1){
        sum-=abs(data[0])*2;
    }
    cout<<sum<<endl;
    
    return 0;
}
