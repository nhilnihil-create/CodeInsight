#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define fastio                        \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL);
#define pb push_back
#define mp make_pair

typedef long long ll;

using namespace std;
struct route{
    int cost, time;
};

int main()
{
    fastio;
    int N, T;
    cin>>N>>T;
    route r[101];
    for(int i=0;i<N;i++){
        cin>>r[i].cost>>r[i].time;
    }
    sort(r, r+N, [&](struct route a, struct route b){
        int x = a.time; int y = b. time;
        return x<y;
    });
    bool flag = false;
    int mc = INT_MAX;
    int i=0;
    for(i=0;i<N;i++){
        if(r[i].time>T){
            break;
        }
        mc = min(mc, r[i].cost);
    }
    if(mc == INT_MAX) cout<<"TLE"<<'\n';
    else cout<<mc<<'\n';
    
    
    return 0;
}