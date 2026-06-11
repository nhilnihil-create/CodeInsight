#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> k(m);
    vector<vector<int> > s(m);
    for(int i=0;i<m;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            int A;
            cin>>A;
            s[i].push_back(A-1);
        }
    }
    vector<int> p(m);
    for(int i=0;i<m;i++) cin>>p[i];
    int ans=0;
    for(int bit=0;bit<(1<<n);bit++){
        bool f=true;
        for(int i=0;i<m;i++){
            int num=0;
            for(int j=0;j<k[i];j++){
                int point=s[i][j];
                if(1 & (bit>>point) ) num++;
            }
            num%=2;
            if(num!=p[i]){
                f=false;
                break;
            }
        }
        if(f) ans++;
    }
    cout<<ans<<endl;
}