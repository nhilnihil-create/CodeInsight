#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <utility>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int d,g;
    cin >> d >> g;
    vector<pii> vec;
    int p,c;
    rep(i,d){
        cin >> p >> c;
        vec.push_back(make_pair(p,c));
    }
    vec.push_back(make_pair(0,0));

    int ans = 1e9;

    rep(i,(1<<d) ){
        int total = 0;  
        int cnt = 0;  
        int last = 0;
        vector<bool> s(d+1,false);

        rep(j,d){
            if((i & (1 << j)) != 0){
                s[j] = true;
            }
        }


        rep(j,d){
            if(s[j]){
                total += vec[j].first * (100 * (j+1));
                total += vec[j].second;
                cnt += vec[j].first;
                last = j;
            }
        }

        last++;

        if( vec[last].first == 0){
            for(int j = last-2; j>=0;j--){
                if(!s[j]){
                    last = j;
                    break;
                }
            }
        }

        if(total < g){
            int ls = 100*(last+1);
            if(g-total > vec[last].first * ls){
                continue;
            }else{
                int tmp = (g-total+ls-1)/ls;
                if(tmp > vec[last].first){
                    continue;
                }else{
                    ans = min(ans,cnt + tmp);
                }
            }
        }else{
            ans = min(ans,cnt);
        }
    }

    cout << ans << endl;
    return 0;
}