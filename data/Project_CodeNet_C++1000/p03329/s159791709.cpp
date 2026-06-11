#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N;
    cin>>N;
    int t = 6,s = 9;
    vector<int> v(100010,INF);
    v[0]=0;
    vector<int> a;
    a.push_back(1);
    while(t<100010){
        a.push_back(t);
        t*=6;
    }
    while(s<100010){
        a.push_back(s);
        s *= 9;
    }
    int cnt = 0;
    while(v[N]==INF){
        rep(i,100010){
            if(v[i]==cnt){
                for(auto x:a){
                    if(x+i<100010){
                        chmin(v[i+x],cnt+1);
                    }
                }
            }
        }
        cnt++;
    }
    cout<<v[N]<<endl;
}