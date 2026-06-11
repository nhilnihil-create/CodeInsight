#include <bits/stdc++.h>
using namespace std;
#define rep(i,e) for(int i= 0; i< (int)(e); i++)
#define reps(i,s,e) for(int i = s; i < (int)(e); i++)
#define repr(i,s,e) for(int i = s; i > (int)(e); i--)
#define pb push_back
typedef long long ll;
const ll INF = 1LL << 60;

int main()
{
    ll n,c;
    cin >> n >> c;
    vector<ll> x(n+1),v(n+1);
    reps(i,1,n+1){
        cin >> x[i] >> v[i];
    }
    ll ans = 0;

    ll cal = 0;
    ll tmp_cal_max = 0;
    vector<ll> cal_max(n+1);
    reps(i,1,n+1){
        cal += (v[i]-(x[i]-x[i-1]));
        if(cal > tmp_cal_max){
            tmp_cal_max = cal;
        }
        cal_max[i] = tmp_cal_max;
    }
    ans = max(ans,cal_max[n]);

    ll reverse_cal = 0;
    repr(i,n,1){
        if(i==n){
            reverse_cal = v[n]-2*(c-x[n]);
        }else{
            reverse_cal += v[i]-2*(x[i+1]-x[i]);
        }
        ll tmp_ans = reverse_cal +cal_max[i-1];
        ans = max(ans,tmp_ans);
    }

    cal = 0;
    tmp_cal_max = 0;
    cal_max.assign(n+1,0);
    repr(i,n,0){
        if(i==n){
            cal += v[n]-(c-x[n]);
        }else{
            cal += (v[i]-(x[i+1]-x[i]));
        }
        if(cal > tmp_cal_max){
            tmp_cal_max = cal;
        }
        cal_max[i] = tmp_cal_max;
    }
    ans = max(ans,cal_max[1]);

    reverse_cal = 0;
    reps(i,1,n){
        reverse_cal += v[i]-2*(x[i]-x[i-1]);
        ll tmp_ans = reverse_cal +cal_max[i+1];
        ans = max(ans,tmp_ans);
    }
    

    cout << ans;
}
