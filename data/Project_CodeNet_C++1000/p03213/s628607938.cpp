#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    int n; cin >> n;
    map<int,int> mp;
    for(int i = 2; i <= n; i++){
        int div = 2;
        int tmp = i;
        for(int j = 2; j*j <= tmp; j++){
            while(tmp % j == 0){
                mp[j]++;
                tmp /= j;
            }
        }
        if(tmp != 1) mp[tmp]++;
    }
    int ans = 0;
    vector<int> fac;
    for(auto i : mp){
        //cout << i.first << ' ' << i.second << endl;
        fac.push_back(i.second);
    }
    int s = fac.size();
    sort(fac.begin(),fac.end());
    for(int i = 0; i < s; i++){
        if(fac[i] >= 74) ans++;
    }
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            if(i == j) continue;
            if(fac[i] >= 2 && fac[j] >= 24) ans++;
            if(fac[i] >= 4 && fac[j] >= 14) ans++;
            
        }
    }
    int tmp = 0;
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            for(int k = 0; k < s; k++){
                if(i == j || j == k || i == k) continue;
                if(fac[i] >= 2 && fac[j] >= 4 && fac[k] >= 4) tmp++;
            }
        }
    }
    ans += (tmp/2);
    cout << ans << endl;
}