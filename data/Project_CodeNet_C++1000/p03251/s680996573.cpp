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
const double PI=3.14159265359;

int main() {
    int N, M, X, Y;
    cin>>N>>M>>X>>Y;
    vector<int> x(N), y(M);
    for(int i=0;i<N;++i){
        cin>>x[i];
    }
    for(int i=0;i<M;++i){
        cin>>y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    bool ans = false;
    for(int i=X+1;i<=Y;++i){
        if((x[N-1]<i) & (i<=y[0])) ans = true;
    }
    if(ans) cout<<"No War"<<endl;
    else cout<<"War"<<endl;
}

