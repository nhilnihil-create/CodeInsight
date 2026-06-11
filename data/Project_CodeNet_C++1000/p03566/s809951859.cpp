typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
    ll n,t[101];
    double v[101];
    std::cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
        sum += t[i];
    }
    ll now = 0;
    std::map<double, double> minr;
    for (double i = 0; i <= sum; i+=0.5) {
        minr[i] = sum-i;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        
        for (double j = 0; j <= now; j+=0.5) {
            minr[j] = min(minr[j],v[i]+now-j);
        }
        for (double j = now; j <= now+t[i]; j+=0.5) {
            minr[j] = min(minr[j],v[i]);
        }
        now += t[i];
    }
    
    
    double a=0;
    double result = 0;
    double b=0;
    for (double i = 0.5; i <= sum; i+=0.5) {
        b = a;
        if(a <= minr[i]-0.5){
            a+=0.5;
        }else if(a == minr[i]){
            
        }else{
            a-=0.5;
        }
        // std::cout << a<<" "<<minr[i]<< std::endl;
        result += (b+a)/4.0;
    }
    std::cout << setprecision(10)<<result << std::endl;
}
