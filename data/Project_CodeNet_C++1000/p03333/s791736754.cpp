#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    int n;
    cin >> n;
    vector<pair<ll,ll> > p(n),q(n);
    rep(i,n){
        cin >> p[i].first >> q[i].first;
        p[i].second = (ll)i;
        q[i].second = (ll)i;
    }
    sort(p.begin(),p.end(),greater<pair<ll,ll> >());
    sort(q.begin(),q.end()); 
    vector<bool>flag(n);
    ll t = 0;
    int x = 0;
    int y = 0;
    int cnt = 0;
    ll tmp = 0;
    bool r = 1;
    
        while(cnt < n){
            //cout << t << " " <<r <<endl;
            if(r){
                if(flag[p[x].second]){
                    x++;
                    continue;
                }
                if(t>p[x].first){
                    break;
                }
                tmp += abs(t-p[x].first);
                flag[p[x].second]=1;
                t = p[x].first;
                x++;
                cnt++;
                r=0;
            }else{
                if(flag[q[y].second]){
                    y++;
                    continue;
                }
                if(t<q[y].first){
                    break;
                }
                tmp += abs(t-q[y].first);
                flag[q[y].second]=1;
                t = q[y].first;
                y++;
                cnt++;
                r=1;
            }

        }
        tmp += abs(t);
    
    ll ans = tmp;
    vector<bool>flag2(n);
    t = 0;
    x = 0;
    y = 0;
    cnt = 0;
    tmp = 0;
    r = 0;
    
        while(cnt < n){
            //cout << t << " " <<r <<endl;
            if(r){
                if(flag2[p[x].second]){
                    x++;
                    continue;
                }
                if(t>p[x].first){
                    break;
                }
                tmp += abs(t-p[x].first);
                flag2[p[x].second]=1;
                t = p[x].first;
                x++;
                cnt++;
                r=0;
            }else{
                if(flag2[q[y].second]){
                    y++;
                    continue;
                }
                if(t<q[y].first){
                    break;
                }
                tmp += abs(t-q[y].first);
                flag2[q[y].second]=1;
                t = q[y].first;
                y++;
                cnt++;
                r=1;
            }

        }
        tmp += abs(t);
    
    cout << max(ans,tmp) << endl;
    return 0;
}