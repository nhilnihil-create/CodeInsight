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
    int n,k;
    cin>>n>>k;
    cout<<n-k+1<<endl;
    return 0;
}