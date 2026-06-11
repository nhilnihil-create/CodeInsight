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
typedef pair<ll,ll > P;
typedef pair<P,ll>Q;

int main(void){
    int n;
    cin>>n;
    vector<ll>a(n),b(n);
    ll sa = 0,sb = 0;
    for(int i=0;i<n;i++)cin>>a[i],sa+=a[i];
    for(int i=0;i<n;i++)cin>>b[i],sb+=b[i];
    ll s = sb - sa;
    ll pl = 0;
    ll mi = 0;
    for(int i=0;i<n;i++){
        if(a[i]-b[i]>0)pl += a[i]-b[i];
        else{
            if(a[i]-b[i]<0){
                mi += (b[i]-a[i])/2;
                if((b[i]-a[i])%2==1)mi++;
            }
        }
    }
    if(pl<=s && mi<=s)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}