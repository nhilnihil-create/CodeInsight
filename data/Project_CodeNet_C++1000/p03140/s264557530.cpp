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
    string a,b,c;
    cin>>n>>a>>b>>c;

    int ans=0;
    rep(i,0,n){
        if(a[i]!=b[i]&&b[i]!=c[i]&&a[i]!=c[i])ans+=2;
        else if((a[i]==b[i]&&b[i]!=c[i]&&a[i]!=c[i])||
                (a[i]!=b[i]&&b[i]==c[i]&&a[i]!=c[i])||
                (a[i]!=b[i]&&b[i]!=c[i]&&a[i]==c[i]))ans+=1;
    }
    cout<<ans<<endl;
    return 0;
}