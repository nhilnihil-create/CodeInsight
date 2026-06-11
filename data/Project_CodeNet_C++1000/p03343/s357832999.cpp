#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iomanip>
#include<bitset>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n,k,q;
    cin >> n >> k >> q;
    vector<LL> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    LL ans = 1333333333333333;

    for(int i = 0; i < n; i++){
        vector<LL> b;
        for(int j = 0; j < n; j++){
            if(a[j] >= a[i]){
                vector<LL> t;
                bool flag = true;
                for(; j < n; j++){
                    if(a[j] < a[i]){
                        sort(t.begin(),t.end());
                        for(int l = 0; k+l <= t.size(); l++){
                            b.push_back(t[l]);
                        }
                        
                        flag = false;
                        break;
                    }
                    t.push_back(a[j]);
                }
                if(flag){
                    sort(t.begin(),t.end());
                    for(int l = 0; k+l <= (int)t.size(); l++){
                        b.push_back(t[l]);
                    }
                }
            }
        }
        sort(b.begin(),b.end());
        if(b.size() >= q){
            ans = min(ans,b[q-1] - b[0]);
        }
    }
    

    cout << ans << endl;
    
    return 0;
}