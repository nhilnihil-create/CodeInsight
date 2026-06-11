    // AGC 028 A
    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define mod 1000000007
    #define MAX 100000
    void inarray(int a[], int n){
        for(int i = 0; i < n; i++) cin >> a[i];
    }

    // 最大公約数
    ll gcd(ll a, ll b){
        // a > b
        if(b == 0) return a;
        else return  gcd(b, a%b);
    }

    // 最小公倍数
    ll lcm(ll a, ll b){
        // a > b
        return (a*b)/gcd(a,b);
    }

    int main(){
        ll n,m; cin >> n >> m;
        string s,t; cin >> s >> t;
        if(n < m){
            int w = n; n = m; m = w;
            string W = s; s = t; t = W;
        }
        ll ans = lcm(n,m);
        int sch[n], tch[m];
        for(int i = 0; i < n; i++){
            sch[i] = i*(ans/n) +1;
        }
        for(int i = 0; i < m; i++){
            tch[i] = i*(ans/m) +1;
        }
        int j = 0;
        for(int i = 0; i < n && j < m;){
            if(sch[i] == tch[j]){
                if(s[i] != t[j]){
                    cout << -1 << endl;
                    return 0;
                }
                j++;
            }else if(sch[i] < tch[j]){
                i++;
            }else{
                j++;
            }
        }

        cout << ans << endl;
        return 0;
    }