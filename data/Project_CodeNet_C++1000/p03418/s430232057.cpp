#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <set>
//#inlcude<stringstream>
#define ll long long
#define MODD 1000000007
using namespace std;

int main() {
    ll n ,k;cin>>n>>k;
    ll sum=0;
    if(k==0)cout<<n*n<<endl;
    else {
        for(ll i = k+1;i<=n;i++){
            sum+=(n/i)*(i-k);
            if(n%i>=k) sum+=n%i-k+1;
        }
        cout<<sum<<endl;
    }

    return 0;
}
