#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int n;
    cin>>n;

    int ans=INF;
    rep(i,1,n){
        int a=i;
        int b=n-i;
        int a_sum=0,b_sum=0;

        while(a/10){
            a_sum+=a%10;
            a/=10;
        }
        a_sum+=a;

        while(b/10){
            b_sum+=b%10;
            b/=10;
        }
        b_sum+=b;

        ans=min(ans,a_sum+b_sum);
    }
    cout<<ans<<endl;
    return 0;
}