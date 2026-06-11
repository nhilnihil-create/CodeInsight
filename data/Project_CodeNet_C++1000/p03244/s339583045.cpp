#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin>>n;
    vector<int> v(n);
    rep(i,n)cin>>v[i];
    map<int,int> ocnt, ecnt;
    for(int i=0; i<n; i++){
        if(i%2==0){
            ecnt[v[i]]++;
        }else{
            ocnt[v[i]]++;
        }
    }
    P o1,o2,e1,e2;
    int nax = 0;
    for(auto a : ocnt){
        if(a.second > nax){
            o1 = a;
            nax = a.second;
        }
    }
    nax = 0;
    for(auto a : ocnt){
        if(a.second > nax && o1.first != a.first){
            o2 = a;
            nax = a.second;
        }
    }
    nax = 0;
    for(auto a : ecnt){
        if(a.second > nax){
            e1 = a;
            nax = a.second;
        }
    }
    nax = 0;
    for(auto a : ecnt){
        if(a.second > nax && e1.first != a.first){
            e2 = a;
            nax = a.second;
        }
    }
    if(o1.first != e1.first){
        cout<<n-o1.second-e1.second<<endl;
    } else{
        int t = max(o1.second+e2.second, o2.second+e1.second);
        cout<<n-t<<endl;
    }
    return 0;

}