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
    int s;
    cin>>s;
    int cnt=1;
    int ans;
    if(s==1 || s==2){
        cout<<4<<endl;
        return 0;
    }

    while(1){
        if(s==4){
            ans=cnt+3;
            break;
        }

        if(s%2==0){
            s/=2;
        }else{
            s=s*3+1;
        }
        cnt++;
    }  
    cout<<ans<<endl;
}