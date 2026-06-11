#include <iostream>
using namespace std;
int main(){
    long long n, cnt=0;
    cin >> n;
    for(long long i=1; i*i<=n; i++){
        if(n % i != 0){
            continue;
        }
        long long a = i, m = n / i - 1;
        if(m > a) cnt += m;
    }
    cout << cnt << endl;
    return 0;
}