#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
    int N, M;
    cin>>N>>M;
    vector<pair<int, int> > arr(M);
    int a, b;
    for(int i=0;i<M;++i){
        cin>>a>>b;
        arr[i] = mp(b, a);
    }
    sort(arr.begin(), arr.end());
    int ans = 1;
    int down = arr[0].fi;
    for(int i=1;i<M;++i){
        if(down <= arr[i].se){
            ans++;
            down = arr[i].fi; 
        }
    }
    cout<<ans<<endl;
}

