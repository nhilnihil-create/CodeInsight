#include <bits/stdc++.h>
using namespace std;
#define MD 1000000007
typedef long long int ll;
typedef pair<ll, ll> P;
template <typename T>
std::string tostr(const T &t){std::ostringstream os;os << t;return os.str();}
int dx[4]={1, 0, -1, 0}, dy[4]={0, 1, 0, -1};

int main()
{
    int n,h,w;
    cin>>n>>h>>w;
    int ans=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a>=h && b>=w){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}