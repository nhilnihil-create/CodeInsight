#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;
using ll=long long;
#ifdef ONLINE_JUDGE
#define D(...)
#else
#define D(...)cerr<<__LINE__<<":"<<"["<<#__VA_ARGS__<<"]->",P(__VA_ARGS__)
#endif
void P(){cerr<<endl;} 
template<typename H,typename...T>void P(H h,T...t){cerr<<h<<" ";P(t...);}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,k;cin>>n>>k;
    vector<int>v(n);
    for(auto &x:v)
        cin>>x;
    cout<<ceil(double(n-1)/(k-1))<<endl;



}