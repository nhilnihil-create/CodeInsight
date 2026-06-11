#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);
const int INF=100000000;

int N; vi h;
void input()
{
    cin>>N;
    h.emplace_back(0);
    for(int i=0;i<N;++i){
        int a; cin>>a; h.emplace_back(a);
    }
}

void solve()
{
    int ans=0;
    int plus=0; int minus=0;
    for(int i=0;i<N;++i){
        if(h[i]<=h[i+1]) plus=h[i+1];
        else{
            ans+=plus-minus;
            plus=h[i+1]; minus=h[i+1];
        }
    }
    ans+=plus-minus;
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