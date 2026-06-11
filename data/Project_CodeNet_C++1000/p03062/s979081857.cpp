#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    ll abs_sum=0;
    ll min_num=1'000'000'000;
    
    int count_negative=1;
    rep(i,N){
        ll x;
        cin >> x;
        if(x<0){
            count_negative *=-1;
        }
        
        abs_sum += abs(x);
        min_num = min(min_num, abs(x));
    }
    
    if(count_negative == -1){
        abs_sum -= min_num*2;
    }
   
   cout << abs_sum << endl;
}
