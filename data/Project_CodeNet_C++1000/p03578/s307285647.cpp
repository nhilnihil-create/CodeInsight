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
#include <cassert>
#include <cmath>
#include<cstdint>


#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

vector<int>bitSearch(int bit,int n){
    vector<int>S,False(1,-1);
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}

template<typename A,size_t N,typename T>
void Fill(A(&array)[N],const T &val){
    fill((T*)array,(T*)(array+N),val);
}

const ll INF = 1e10;
int main(){
    int n, m;
    cin >> n;
    VEC(ll, d, n);
    cin >> m;
    VEC(ll, t, m);
    sort(ALL(d));
    sort(ALL(t));

    if(n < m){
        cout << "NO" << endl;
        return 0;
    }

    int now = 0;
    vector<bool> seen(m, false);
    rep(i, m){
        if(t[i] == d[now]){
            now++;
            seen[i] = true;
        }

        else {
            while(now < n){
                now++;
                if(t[i] == d[now]){
                    now++;
                    break;
                }
            }
            if(now >= n)break;
            seen[i] = true;
        }
        if(now >= n)break;
    }
    bool all_seen = true;
    rep(i, m)if(!seen[i])all_seen = false;

    cout << (all_seen ? "YES" : "NO") << endl;
}