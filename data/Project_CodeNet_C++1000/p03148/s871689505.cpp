#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <stack>
#include <numeric>
#include <algorithm>
#include <tuple>
#include <stdio.h>
#include <bitset>
#include <limits.h>
#include <complex>
#include <deque>
#include <iomanip>
#include <list>
#include <cstring>
using namespace std;
#define pi pair<int,int>
#define pl pair<long long,long long>
#define chmax(a,b) (a<b ? a=b:0)
#define chmin(a,b) (a>b ? a=b:0)
#define en cout << endl //セミコロンつけろ
//#define MM 1000000000
//#define MOD MM+7
const int MM = 1e9;
const int MOD = MM+7;
const long double PI = acos(-1);
const long long INF = 1e15;
int dx[8] = {-1,0,1,0,-1,-1,1,1};
int dy[8] = {0,-1,0,1,-1,1,1,-1};
// 'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122
template<typename T>
T GCD(T u,T v){
    return v ? GCD(v,u%v) : u;
}
template<typename T>
T LCM(T x,T y){
    T gc = GCD(x,y);
    return x*y/gc;
}

struct edge {
    int time, x, y;
};

int main(){
    long long N,K; cin >> N >> K;
    vector<long long> t(N),d(N);
    vector<pair<long long,long long> > p(N);
    for (int i = 0; i < N; i++){
        cin >> t[i] >> d[i];
        p[i] = {d[i],t[i]};
    }
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    map<long long,long long> vari;
    long long sum = 0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long> >,greater<pair<long long,long long> > > pq;
    for (int i = 0; i < K; i++){
        vari[p[i].second]++;
        sum += p[i].first;
        pq.push(p[i]);
    }
    //cout << "n1 = " << vari.size() << endl;
    sum += vari.size()*vari.size();
    //cout << sum << endl;
    long long total = sum;
    for (int i = K; i < N; i++){
        if (vari[p[i].second] != 0) continue;
        while (!pq.empty()){
            pair<long long,long long> se = pq.top();
            pq.pop();

            if (vari[se.second] > 1){
                //cout << se.first << endl;
                //cout << p[i].first << " " << p[i].second << endl;
                long long n = vari.size();
                //cout << "n2 = " << n << endl;
                total = total + p[i].first - se.first + n*n - (n-1)*(n-1);
                vari[se.second]--;
                vari[p[i].second]++;
                sum = max(sum,total);
                break;
            }
        }
    }
    cout << sum << endl;
}