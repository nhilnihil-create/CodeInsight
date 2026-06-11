#include <iostream>
#include <map>
#include <cstdio>
#include <string>
#include <iterator>
#include <vector>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main( ) {
    // freopen("B.01.in","r",stdin);
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n,m;
    char s[256];
    scanf("%d\n",&n);
    map<string,int> nmap;
    while (n--)
    {

        scanf("%s\n",s);
        nmap[s]++;
    }
    scanf("%d\n",&m);
    // map<string,int> mmap;
    while (m--)
    {
        scanf("%s\n",s);
        nmap[s]--;
    }
    int mx=INT32_MIN;
    trav(it, nmap){
        if(it.second>mx){
            mx=it.second;
        }
    }
    // mx = (mx<0)?0:mx;
    printf("%d\n",(mx<0)?0:mx);
    return 0;
}