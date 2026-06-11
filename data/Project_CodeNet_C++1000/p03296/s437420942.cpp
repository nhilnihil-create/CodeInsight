#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <utility>
#include <queue>
#include <bitset>
#include <math.h>
#include <numeric>

using namespace std;
 
#define rep(i,m,n) for(int i=m;i<(int)(n);i++)
#define endl '\n'
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin>>n;
    vector<int> a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int res=0;
    rep(i,0,n-1){
        if(a[i]==a[i+1]){
            res++;
            a[i+1]=i+1e9;//被らない数字(iが可変なのでなんでも)
        }
    }
    cout<<res<<endl;
}