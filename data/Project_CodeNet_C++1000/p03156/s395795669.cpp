#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#include<cstdint>


     
#define INF 1e9
#define LINF 1e19
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define pb push_back
#define sz size()
     
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

     
const ll MOD = 1e9 + 7;
const ll ZER = 0;



int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> cnt(3, 0);
    rep(i, n){
        int p;
        cin >> p;
        if(p <= a)cnt[0]++;
        else if(a < p && p <= b)cnt[1]++;
        else cnt[2]++;
    }
    sort(ALL(cnt));
    cout << cnt[0] << endl;
}



