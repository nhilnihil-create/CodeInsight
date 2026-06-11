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
bool hantei(int a){
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int q;
    cin>>q;
    vector<int> sosuu(100010,0);
    sosuu[3]=1;
    vector<int> ans(q);
    for(int i=3;i<100010;i++){
        if(i%2==0){
            sosuu[i]=sosuu[i-1];
        }else{
            sosuu[i]=sosuu[i-1];
            if(hantei(i) && hantei((i+1)/2)){
                sosuu[i]++;
            }
        }
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        ans[i]=sosuu[r]-sosuu[l-1];
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }
}