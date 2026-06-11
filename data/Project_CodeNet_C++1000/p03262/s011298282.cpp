#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<P,P>
#define T tuple<int,int,int> 
using namespace std;

int gcdo(int a, int b){
    if(a<b) swap(a,b);
    int r=1;
    while(r){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}

int main(){
    int n,x; cin >> n >> x;
    vector<int> p(n);
    rep(i,n){
        int d; cin >> d;
        p[i]=abs(x-d);
    }
    int ans;
    if(n==1) ans=p[0];
    else ans=gcdo(p[0],p[1]);
    for(int i=2; i<n; i++){
        ans = gcdo(ans,p[i]);
    }
 
    cout << ans << endl;
return 0;
}