#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

ll ni(ll a,ll b){
    if(b==0) return 1;
    else if(b%2==0) return ni(a,b/2)*ni(a,b/2);
    else return ni(a,b-1)*a;
}

int main(){
    int n; cin >> n;
    map<int,int> p;
    for(int i=2; i<=n; i++){
        int now=i;
        for(int j=2; j<=sqrt(i); j++){
            while(now%j==0){
                p[j]++;
                now/=j;
            }
        }
        if(now!=1) p[now]++;
    }
    int num4=0;
    int num2=0;
    int num24=0;
    int num14=0;
    int num74=0;
    for(auto x : p){
        if(x.second>=4) num4++;
        if(x.second>=2) num2++;
        if(x.second>=14) num14++;
        if(x.second>=24) num24++;
        if(x.second>=74) num74++;
    }
    int ans=(num4*(num4-1)/2)*(num2-2);
    ans+=num14*(num4-1);
    ans+=num24*(num2-1);
    ans+=num74;
    cout << ans << endl;
    return 0;
}
