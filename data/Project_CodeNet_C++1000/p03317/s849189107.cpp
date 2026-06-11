#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define fastio                        \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL);
#define pb push_back
#define mp make_pair

typedef long long ll;

using namespace std;

int main()
{
    fastio;
    int n, k;
    cin>>n>>k;
    if((n-1)%(k-1)==0)
    cout << (n-1)/(k-1)<<endl;
    else cout<<(n-1)/(k-1) +1<<endl;

    //cout<<(n+n/k +1)/k <<endl;
    
    return 0;
}