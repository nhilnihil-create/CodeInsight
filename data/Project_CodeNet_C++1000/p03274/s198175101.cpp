#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define rep11(i, n) for (int i = 1; i < (int)(n); ++i)
#define repo(i, o, n) for (int i = o; i < (int)(n); ++i)
#define repm(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(n) push_back(n)
#define mp make_pair
#define MOD 1002000007
#define INF LONG_LONG_MAX
typedef pair<long long, long long> P;
int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long>x(n);
    rep(i,n){
        cin>>x[i];
    }
    vector<long long>y(n-(k-1));
    rep(i,n-(k-1)){
        long long j=i+(k-1);
        if(abs(x[i]+x[j])==abs(x[i])+abs(x[j])){
            y[i]=max(abs(x[i]),abs(x[j]));
        }
        else{
            y[i]=min(abs(x[i]*2)+abs(x[j]),abs(x[i])+abs(x[j]*2));
        }
    }
    sort(y.begin(),y.end());
    
    cout<<y[0]<<endl;
}