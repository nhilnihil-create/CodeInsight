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
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

int main(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    ll anum,bnum;
    anum=0; bnum=0;
    for(int i=0;i<n;i++){
        if(a[i]>=b[i]){
            bnum+=a[i]-b[i];
        }else{
            anum+=(b[i]-a[i])/2;
            anum+=(b[i]-a[i])%2;
            bnum+=(b[i]-a[i])%2;
        }
        //cout<<anum<<" "<<bnum<<endl;
    }
    if(anum>=bnum){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}