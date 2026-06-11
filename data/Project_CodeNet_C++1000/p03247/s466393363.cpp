typedef long long ll;
#include <bits/stdc++.h>

using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll n;
ll x[1000],y[1000];

int main() {
    std::cin >> n;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        std::cin >> x[i]>>y[i];
        if(i!=0){
            flag = flag && (x[i]+y[i] + (ll)2e9) %2 == (x[i-1]+y[i-1]+(ll)2e9)%2;
            if(!flag){
                std::cout << -1 << std::endl;
                return 0;
            }
        }
    }
    string ans[1000];
    ll now[2];
    bool flag_1 = false;
    for (int j = 0; j < n; j++) {
        now[0] =0;
        now[1] =0;
        for (int i = 38; i>=0; i--) {
            // 右にいったときの距離
            ll r_distance = (ll)abs( x[j] - (now[0] + (ll)pow(2,i) ) ) + (ll)abs( y[j] - now[1] );
            ll l_distance = (ll)abs( x[j] - (now[0] - (ll)pow(2,i) ) ) + (ll)abs( y[j] - now[1] );
            ll u_distance = (ll)abs( x[j] - now[0] ) + (ll)abs( y[j] - (now[1] + (ll)pow(2,i)) );
            ll d_distance = (ll)abs( x[j] - now[0] ) + (ll)abs( y[j] - (now[1] - (ll)pow(2,i)) );
            
            ll mind = min({r_distance,l_distance,u_distance,d_distance});
            
            // 左
            if(  (ll)abs( x[j] - (now[0] - (ll)pow(2,i) ) ) + (ll)abs( y[j] - now[1] ) == mind ){
                now[0] -= (ll)pow(2,i);
                ans[j] = ans[j]+ 'L';
            // 上
            }else if(  (ll)abs( x[j] - now[0] ) + (ll)abs( y[j] - (now[1] + (ll)pow(2,i) ) ) == mind ){
                now[1] += (ll)pow(2,i);
                ans[j] = ans[j]+ 'U';
            // 下
            }else if(  (ll)abs( x[j] - (now[0] - 0 ) ) + (ll)abs( y[j] - (now[1] - (ll)pow(2,i) ) ) == mind ){
                now[1] -= (ll)pow(2,i);
                ans[j] = ans[j]+ 'D';
            }else{
                now[0] += (ll)pow(2,i);
                ans[j] = ans[j]+ 'R';
            }
            
        }
        if((ll)abs(now[0]-x[j])+(ll)abs(now[1]-y[j]) == 1 ){
            flag_1 = true;
            ll i = 0;
            ll distance = (ll)abs( x[j] - (now[0] + (ll)pow(2,i) ) ) + (ll)abs( y[j] - (now[1] + 0 ) );
            // 左
            if(  (ll)abs( x[j] - (now[0] - (ll)pow(2,i) ) ) + (ll)abs( y[j] - (now[1] + 0 ) ) < distance ){
                now[0] -= (ll)pow(2,i);
                ans[j] = ans[j]+ 'L';
            // 上
            }else if(  (ll)abs( x[j] - (now[0] - 0 ) ) + (ll)abs( y[j] - (now[1] + (ll)pow(2,i) ) ) < distance ){
                now[1] += (ll)pow(2,i);
                ans[j] = ans[j]+ 'U';
            // 下
            }else if(  (ll)abs( x[j] - (now[0] - 0 ) ) + (ll)abs( y[j] - (now[1] - (ll)pow(2,i) ) ) < distance ){
                now[1] -= (ll)pow(2,i);
                ans[j] = ans[j]+ 'D';
            }else{
                now[0] += (ll)pow(2,i);
                ans[j] = ans[j]+ 'R';
            }
        }
    }
    ll m= 39;
    
    if(flag_1){
        m++;
        std::cout << m << std::endl;
        for (int i = 38; i>=1; i--) {
            std::cout << (ll)pow(2,i)<<" ";
        }
        std::cout << 1<<" "<<1 << std::endl;
    }else{
        std::cout << m << std::endl;
        for (int i = 38; i>=1; i--) {
            std::cout << (ll)pow(2,i)<<" ";
        }
        std::cout << 1 << std::endl;
    }
    
    for (int i = 0; i < n; i++) {
        
        std::cout << ans[i] << std::endl;
    }
    
}
