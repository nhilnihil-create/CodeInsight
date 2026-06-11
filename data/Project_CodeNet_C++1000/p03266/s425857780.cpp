#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(){
    ll n,k; 
    cin >> n >> k;
    if(k % 2 == 1){
        ll a = n / k;
        cout << a * a * a << endl;
    }else{
        ll b = 0, c = 0;
        rep(i,n){
            if((i + 1) % k == k / 2){
                b++;
            }
        }
        c = n / k;
    
    cout << b * b * b + c * c * c << endl;
    }
}
