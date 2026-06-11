#include <bits/stdc++.h>
#define rep(n) for(int i=0;i<n;i++)
#define reps(i,s,n) for(int i=s;i<n;i++)
#define rep_bit(n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ll long long
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
using namespace std;
typedef vector<vector<int> > Graph;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;



int main(){

    ll n;
    cin >> n;
    vl dif(n);
    
    vl a(n),b(n);
    rep(n) cin >> a.at(i);
    rep(n) cin >> b.at(i);
    rep(n) dif.at(i) = a.at(i)-b.at(i);
    
        sort(all(dif));
        ll sum = 0;
        rep(n) sum += dif.at(i);
        ll sum_mi = 0;
        ll cnt = 0;
        if(sum<0) cout << -1 << endl;
        else{
            ll time = 0;
            while(dif.at(time) < 0){
                sum_mi += dif.at(time);
                cnt++;
                time++;
            } 
            ll now = n-1;
            while(sum_mi < 0){
                sum_mi += dif.at(now);
                now--;
                cnt++;
            }
            cout << cnt << endl;
        }
    

    return 0;
}
