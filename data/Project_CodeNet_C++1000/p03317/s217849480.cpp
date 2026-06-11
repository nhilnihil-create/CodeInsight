#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int N,K; 
// vi A;
void input()
{
    cin>>N>>K;
    // for(int i=0;i<N;++i){
    //     int a; cin>>a; A.emplace_back(a);
    // }
}

void solve()
{
    int ans=(N-1)/(K-1);
    if((N-1)%(K-1)!=0) ++ans;
    cout<<ans<<endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}