//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;



int main() {
    int n,cnt=0,ju=0; cin>>n;
    for(int i=2;i<=55555;i++){
        if(ju==1) break;
        for(int j=2;j*j<=i;j++){
            if(i%j==0) break;
            if((j+1)*(j+1)>i && i%5==1){
                cout<<i; cnt++;
                if(n!=cnt) cout<<" ";
                if(n==cnt){
                    cout<<endl;
                    ju=1;
                }
            }
        }
    }
}