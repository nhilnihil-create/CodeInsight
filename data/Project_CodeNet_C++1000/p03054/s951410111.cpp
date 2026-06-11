#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll,ll> P;
typedef pair<ll,pair<ll,ll>> p;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
static const int MAX_SIZE = 1 << 17; //segment tree のサイズ。この実装では2べきにする必要がある。 2^17 ≒ 1.3 * 10^5

int main(){
    bool flag=true;
    int H,W,N,sr,sc,l,r,u,d;
    cin>>H>>W>>N;
    cin>>sr>>sc;
    string S,T;
    cin>>S>>T;

    l=1; r=W; u=1; d=H;
    for(int i=N-1;i>=0;i--){
        if(T[i]=='U'){
            d=min(d+1,H);
        }else if(T[i]=='D'){
            u=max(1,u-1);
        }else if(T[i]=='L'){
            r=min(r+1,W);
        }else l=max(1,l-1);

        if(S[i]=='U'){
            u++;
            if(u>d) flag=false;
        }else if(S[i]=='D'){
            d--;
            if(d<u) flag=false;
        }else if(S[i]=='L'){
            l++;
            if(l>r) flag=false;
        }else{
            r--;
            if(r<l) flag=false;
        }
    }
    if(flag && l<=sc && sc<=r && u<=sr && sr<=d)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

