#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

vector<ll> vec[90010];
int main(){

    rep(i,90010) vec[i].push_back(0);
    
    int h,w,d;
    cin >> h >> w >> d;
    map<int,pii> mp;
    int tmp;
    int q;
    int left,right;
    int cnt = 0;
    ll ans = 0;

    rep(i,h){
        rep(j,w){
            cin >> tmp;
            tmp--;
            mp[tmp] = make_pair(j,i);
        }
    }
    
    rep(i,d){
        for(int j = 0; i+j+d < h*w; j += d){
            pii p1 = mp[i+j];
            pii p2 = mp[i+j+d];
            int dis = abs(p1.first - p2.first);
            dis += abs(p1.second - p2.second);
            if(vec[i].size() > 1){
                dis += vec[i][vec[i].size()-1];
            }
            
            vec[i].push_back(dis);
        }
    }

    

    cin >> q;

    rep(i,q){
        ans = 0;
        cin >> left >> right;
        left--; right--;
        if(left == right){
            cout << 0 << endl;
            continue;
        }
        cnt = (right - left) / d;
        tmp = left % d;
        
        ans += vec[tmp][(right-tmp)/d];
        if((left-tmp)/d > 0){
            ans -= vec[tmp][((left-tmp)/d)];
        }

        cout << ans << endl;
    }

    return 0;
}
