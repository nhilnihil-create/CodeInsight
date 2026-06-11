#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

int main(void){
    ll N, M;
    ll A, B;
    vector<pair<ll, ll> > cost;
    cin>>N>>M;
    rep(i, N){
        cin>>A>>B;
        cost.push_back({A, B});
    }
    sort(all(cost));
    ll count=0, cosc=0;
    rep(i,N){
        if(cost[i].second<M-count){
            count+=cost[i].second;
            cosc+=cost[i].first*cost[i].second;
        }
        else{
            cosc+=(M-count)*cost[i].first;
            break;
        }
        //cout<<cosc<<sp<<count<<endl;
    }
    cout<<cosc<<endl;
    return 0;
}
