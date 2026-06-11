#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll,ll>
#define PP pair<P,P>
using namespace std;

int main(){
    int m,k; cin >> m >> k;
    int f=(int)pow(2,m)-1;
    if(f<k){
        cout << -1 << endl;
        return 0;
    }
    if(m==1 && k==1){
        cout << -1 << endl;
        return 0;
    }
    int f2=f;
    f++;
    f*=2;
    if(k==0){
        rep(i,f2+1){
            printf("%d ",i);
            printf("%d ",i);
        }
        return 0;
    }

    int now=0;
    rep(i,f/2){
        if(k!=now){
            printf("%d ",now);
            now++;
            continue;
        }
        now++;
    }
    now--;
    printf("%d ",k);
    rep(i,f/2){
        if(k!=now){
            printf("%d ",now);
            now--;
            continue;
        }
        now--;
    }
    printf("%d ",k);
return 0;
}

