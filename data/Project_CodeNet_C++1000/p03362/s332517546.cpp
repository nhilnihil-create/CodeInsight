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
//vector<int> sosuu(1,2);

bool sosuu_hantei(int num){
    for(int i=2;i*i<=num;i++){
        if(num%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int> ans(0);
    int i=1;
    int flag=n;
    while(flag){
        int num=5*i+1;
        if(sosuu_hantei(num)){
            ans.push_back(num);
            flag--;
        }
        i++;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}