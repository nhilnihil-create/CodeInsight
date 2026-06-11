#include<bits/stdc++.h>

#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back

using ll = int64_t;

using namespace std;

int n,k;
int64_t v[100];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    REP(i,n) cin >> v[i];

    int64_t ans = 0;

    for(int l = 0;l <= n;l++){
        for(int r = 0;r <= n - l;r++){
            int left = k - (l + r);
            if(left < 0)continue;

            vector<int64_t> a;
            for(int i = 0;i < l;i++){
               a.push_back(v[i]);
            }
            for(int i = 0;i < r;i++){
                a.push_back(v[n-1-i]);
            }
            sort(a.begin(),a.end());

            int64_t sum = 0;
            for(auto i : a) sum += i;

            for(int i = 0;i < min((int)a.size(),left);i++){
               if(a[i] < 0)sum -= a[i];
               else break;
            }
            ans = max(ans,sum);
        }
    }

    cout << ans << '\n';
}

