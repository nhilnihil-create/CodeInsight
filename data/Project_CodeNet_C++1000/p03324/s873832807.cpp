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
    int d,n;cin>>d>>n;
    if(d==0){
        if(n==100){
            cout<<101;
        }
        else cout<<n;
    }
    else if(d==1){
        if(n==100){
            cout<<10100;
        }
        else cout<<100*n;
    }
    else{
        if(n==100){
            cout<<1010000;
        }
        else cout<<10000*n;
    }



}