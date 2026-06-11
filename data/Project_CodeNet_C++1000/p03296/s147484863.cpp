#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <cstdio>
#include <tuple>
#include <string>
#include <vector> 
#include <set>
#include <string.h>
#include <map>
#include <cmath>
#include <deque>
using ll = long long;
using Graph = vector<vector<int>>;
#include <queue>
#include <stack>

//最大公約数
ll gcd(ll a,ll b){
    if(b == 0LL) return a;
    return gcd(b , a % b);
}

//最小公倍数
ll lcm(ll a,ll b){
    return a / gcd(a,b) * b;

}

//前後を比較
bool compare(int pos,vector<int>& a){
    if(a[pos] == a[pos + 1]) return true;
    else return false;
}

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);

    int pos = 0;
    
    for(int i=0; i < n;i++) cin >> a[i];
    //前から順番に見ていく
    int cnt = 0;
    while(pos < n-1){
        if(compare(pos,a)) cnt++,pos += 2;
        else pos += 1;

    }
    
    cout << cnt << endl;
    
}