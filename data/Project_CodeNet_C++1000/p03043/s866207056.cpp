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
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=1<<18;


int main(){
    ld n,k;
    cin>>n>>k;
    ld ans=0;
    if(n>=k){
        ans+=(n-k+1);
    }
    for(int i=1;i<min(n+1,k);i++){
        ld num=0;
        ld buf=i;
        while(buf<k){
            num++;
            buf*=2;
        }
        ans+=1/pow(2,num);
    }
    ans/=n;
    cout<<setprecision(15)<<ans<<endl;

}