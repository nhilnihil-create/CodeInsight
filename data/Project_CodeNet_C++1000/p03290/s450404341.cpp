#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main() {
    int d, g;
    cin >> d >> g;
    vector<int> p(d);
    vector<int> c(d);
    vector<int> x(d);
    rep(i,d){
        cin >> p[i] >> c[i];
        x[i]=100*(i+1)*p[i]+c[i];
    }
    int ans=1000000000, pr=0, cur=0;
    for (int bit = 0; bit < (1<<d); ++bit) {
        for (int i = 0; i < d; ++i) {
            if (bit & (1<<i)) {
                cur+=x[i];
                pr+=p[i];
            }
        }
        if(cur>=g){
            ans=min(ans,pr);
        }else{
            int y=g-cur;
            for(int j=d-1; j>=0; --j){
                if(bit & (1<<j)) continue;
                for(int k=0; k < p[j]-1; ++k){
                    ++pr;
                    y-=100*(j+1);
                    if(y<=0) {
                        ans=min(ans,pr);
                        break;
                    }
                }
                break;
            }
        }
        cur=0; pr=0;
    }
    cout << ans << "\n";
    return 0;
}