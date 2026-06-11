#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << "\t";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a;
    vector<ll> sum;
    ll sum_cnt = 0;
    sum.push_back(0);
    rep(i, n){ 
        int tmp; cin >> tmp; 
        a.push_back(tmp);    
        sum_cnt += a[i];
        sum.push_back(sum_cnt);
    }
    vector<ll> sum_list;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n+1; j++)
        {
            sum_list.push_back(sum[j]-sum[i]);
        }        
    }
    //show(sum);
    //show(sum_list);

    vector<bool> use(sum_list.size(), false);
    int max_bit = 0;
    for(int bit = 40; bit >= 0; bit--){
        int cnt = 0;
        int cnt_true = 0;
        rep(i, sum_list.size()){
            if (((sum_list[i]>>bit)&1) == 1) {
                cnt++;
                if (use[i]) cnt_true++;
            }
        }
        if (cnt < k){
            continue;
        } else {
            if (max_bit == 0){
                max_bit = bit;
                rep(i, sum_list.size()){
                    if ((sum_list[i]>>bit)&1 == 1) use[i] = true;
                }
            } else {
                if (cnt_true >= k){
                    rep(i, sum_list.size()){
                        if ((((sum_list[i]>>bit)&1) == 0) && use[i]) use[i] = false;
                    }
                }
            }
        }
        //rep(i, sum_list.size()) cout << use[i] << "\t";
        //cout << bit << ":"<< cnt_true << endl;
    }
    ll sum_bit = (1ll<<40) - 1;
    rep(i, sum_list.size()){
        if (use[i]) sum_bit&=sum_list[i];
    }
    cout << sum_bit << endl;
}
