#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int N,M; vi X;
void input()
{
    cin>>N>>M;
    for(int i=0;i<M;++i){
        int a; cin>>a; X.emplace_back(a);
    }
}

void solve()
{
    sort(X.begin(),X.end());
    vi sa;
    for(int i=0;i<M-1;++i) sa.emplace_back(X[i+1]-X[i]);
    sort(sa.begin(),sa.end());
    vi ans(M,0);
    for(int i=1;i<M;++i) ans[i]=ans[i-1]+sa[i-1];
    cout<<ans[((M-N>=0)?(M-N):0)]<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}