#include<iostream>
#include<algorithm>
using namespace std;


unsigned int N, a[200000], b[200000];

long long pow(int a, int x){
    long long ret = 1;
    for(int i = 0; i < x; i++){
        ret *= a;
    }
    return ret;
}


bool is_up(int k){
    for(int i = 0; i < N; i++){
        a[i] %= pow(2, k+1);
        b[i] %= pow(2, k+1);
    }
    sort(b, b+N);
    long long up_count = 0;
    for(int i = 0; i < N; i++){
        up_count += lower_bound(b, b+N, 2*pow(2, k) - a[i]) - lower_bound(b, b+N, pow(2, k) - a[i]);
        up_count += lower_bound(b, b+N, 4*pow(2, k) - a[i]) - lower_bound(b, b+N, 3*pow(2, k) - a[i]);
    }
    return !(up_count % 2 == 0);
}


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    long long ans = 0;
    for(int k = 28; k >= 0; k--){
        if(is_up(k)){
            ans += 1 * pow(2, k);
        }
    }
    cout << ans << endl;
}