#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    void sovle(){
        int N,K;
        cin>>N>>K;
        ll ans=0;
        for(int b=1;b<=N;b++){
            int p=N/b,r=N%b;
            ans+=(ll)p*max(0,b-K);
            ans+=(ll)max(0,r-K+1);
        }
        if(K==0)ans-=N;
        cout<<ans;
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->sovle();
}