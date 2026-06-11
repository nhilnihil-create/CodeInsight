#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<queue>
#include<cmath>
#include<numeric>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<iomanip>
#include<functional>
#include<bitset>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long ll;

int main(){
    int d,g;
    cin>>d>>g;
    int p[d],c[d];
    rep(i,d) cin>>p[i]>>c[i];

    int ans = 1e9;
    for(int mask = 0;mask < (1<<d); ++mask){
        int s = 0,num =0,restmax=-1;
        for(int i=0;i<d;++i){
            if(mask >> i & 1){
                s += 100 * (i+1) * p[i] + c[i];
                num += p[i];
            }
            else{
                restmax = i;
            }
        }
        if(s<g){
            int s1 = 100*(restmax + 1);
            int need = (g -s +s1 -1)/s1;
            if(need >= p[restmax]){
                continue;
            }
            num += need;

        }
        ans = min(ans,num);
    }
    cout<<ans<<endl;


    return 0;
}