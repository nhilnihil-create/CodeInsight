#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N; 
    cin >> N;
    long long ans = 1;
    for(long long i = 0; i < 1000000; i++) {
        if(i*i <= N) {
            ans = i*i;
        }
    }
    cout << ans << endl;
}


