#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int N,X; vi d;

int gcd(int a, int b)
{
    int c=a%b;
    while(c!=0){
        a=b; b=c; c=a%b;
    }
    return b;
}

void input()
{
    cin>>N>>X;
    for(int i=0;i<N;++i){
        int a; cin>>a; 
        d.emplace_back((X-a>0)?X-a:a-X);
    }   
}

void solve()
{
    int ans=d[0];
    for(int i=1; i<d.size(); ++i){
        ans=gcd(ans,d[i]);
    }
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