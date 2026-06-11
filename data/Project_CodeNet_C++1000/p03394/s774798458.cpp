#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main() {
    ll n;
    cin >> n;
    vector<ll> v(n);

    if(n == 3){
        cout << "2 5 63" <<endl;
        return 0;
    }

    int constraint = 30000;
    int num = 0;
    ll sum = 0, subsum = 0;
    for(int i = 2; i < constraint; i++){
        if(i%2==0 || i%3==0 || i%5==0){
            v[num] = i;
            num++;
            sum += ll(i);
        }
        if(num == n){break;}
    }
    if(sum%30 != 0){
        ll ex = (30 - sum%30)%30+30;
        bool flg = true;
        while(flg){
            for(int i = 1; i < ex/2; i++){
                ll ta = v[n-2] + i;
                ll tb = v[n-1] + ex-i;
                if((ta%2==0 || ta%3==0 || ta%5==0)&&(tb%2==0 || tb%3==0 || tb%5==0)){
                    v[n-2] = ta;
                    v[n-1] = tb;
                    flg = false;
                    sum += ex;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
