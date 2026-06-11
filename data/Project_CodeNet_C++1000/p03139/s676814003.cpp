#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descsort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void)
{
    int n,a,b;
    cin>>n>>a>>b;
    int ma=min(a,b);
    int mi=max(0,a+b-n);
    cout<<ma<<" "<<mi<<endl;
    return 0;
}