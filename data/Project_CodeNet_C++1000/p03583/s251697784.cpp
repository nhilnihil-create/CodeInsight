#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> pll;
const int INF=1e9;
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int dis2(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
    ll N;cin>>N;
    for(ll h=1;h<=3500;h++){
        for(ll n=1;n<=3500;n++){
          if(4*h*n-N*n-N*h==0) continue;
            double w=(double)(N*h*n)/(double)(4*h*n-N*n-N*h);
            if(w>=1&&w<=3500&&floor(w)==ceil(w)){
                cout<<h<<' '<<n<<' '<<w<<endl;
                return 0;
            }
        }
    }
}