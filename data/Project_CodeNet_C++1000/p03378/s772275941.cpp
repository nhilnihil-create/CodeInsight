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
    int n,m,x;
    cin>>n>>m>>x;
    int ans1=0;
    int ans2=0;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        if(a<x){
            ans1++;
        }else{
            ans2++;
        }
    }
    cout<<min(ans1,ans2)<<endl;
}