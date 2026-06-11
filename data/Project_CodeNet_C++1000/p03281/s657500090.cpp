#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <bitset>
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)

using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);

   


 
int i, j, N;
cin >> N;
int count;
int ans = 0;
for(i=1;i<=N;i++){
    count = 0;
    if(i%2==1){
  	    for(j = 1; j<=i; j++){
            if(i%j == 0){
       		    count++;
            }
        }
        //if(i==105)cout<<count;

    if(count==8)ans++;
    }
}

  cout<<ans<<endl;
 


    return 0;
}