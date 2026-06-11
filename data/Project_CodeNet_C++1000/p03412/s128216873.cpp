#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    long a[200000];
    long b[200000];
    long a_[200000];
    long b_[200000];
    long ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }
    for(int i = 1; i <= 31; i++){
        long n = ((long)1 << i);
        for(int j = 0; j < N; j++){
            a_[j] = a[j]&(n-1);
            b_[j] = b[j]&(n-1);
        }
        sort(a_, a_+N);
        sort(b_, b_+N);
        long total = 0;
        for(int j = 0; j < N; j++){
            total += (lower_bound(b_, b_+N, n-a_[j]) - lower_bound(b_, b_+N, n/2-a_[j]));
            total += (lower_bound(b_, b_+N, 2*n-a_[j]) - lower_bound(b_, b_+N, n+n/2-a_[j]));
        }
        //cout << total << endl;
        if(total%2 == 1) ans += n/2;
    }
    cout << ans << endl;
}