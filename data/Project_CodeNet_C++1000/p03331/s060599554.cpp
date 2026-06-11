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

    int n_sum=0;
    while(n/10){
        n_sum+=n%10;
        n/=10;
    }
    n_sum+=n;

    if(n_sum==1)cout<<10<<endl;
    else cout<<n_sum<<endl;
    return 0;
}