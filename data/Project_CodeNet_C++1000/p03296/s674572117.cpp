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
    vector<int> a(n);
    rep(i,0,n)cin>>a[i];

    int ans=0,j;
    for(int i=0;i<n;){
        int cnt=1;
        int j=i+1;
        while(a[i]==a[j]){
            cnt++;
            j++;
        }
        i=j;
        ans+=cnt/2;
    }
    cout<<ans<<endl;
    return 0;
}