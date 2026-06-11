#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
using namespace std;
#define INF 2147483647
#define LINF 9223372036854775807
#define MOD 1000000007
//#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define repb(i, n) for (int i = n - 1; i >= 0; i--)
#define MODE 1
#ifdef MODE
#define DEB(X) cout << #X << ": " << X << " ";
#define ARDEB(i, X) cout << #X << "[" << i << "]: " << X[i] << " ";
#define END cout << endl;
#else
#define DEB(X) \
    {          \
    }
#define ARDEB(i, X) \
    {               \
    }
#define END \
    {       \
    }
#endif
typedef pair<int, int> P;
typedef long long ll;

signed main()
{
    string s;
    cin>>s;
    int f=0;
    if(s=="KIHBR")f=1;
    if(s=="AKIHBR")f=1;
    if(s=="AKIHABR")f=1;
    if(s=="AKIHBAR")f=1;
    if(s=="AKIHBRA")f=1;
    if(s=="KIHABR")f=1;
    if(s=="KIHABAR")f=1;
    if(s=="KIHABARA")f=1;
    if(s=="KIHBAR")f=1;
    if(s=="KIHBARA")f=1;
    if(s=="KIHBRA")f=1;
    if(s=="AKIHABAR")f=1;
    if(s=="AKIHABRA")f=1;
    if(s=="KIHABARA")f=1;
    if(s=="AKIHABARA")f=1;
    if(f)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
