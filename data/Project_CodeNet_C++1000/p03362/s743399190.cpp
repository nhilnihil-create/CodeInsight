#include<bits/stdc++.h>
using namespace std;

#define LL long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n; n = 55555;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }    

    vector<int> v;
    for(int i = 2; i <= 55555; i++) 
        if(is_prime[i] && i % 5 == 1) 
            v.push_back(i);

    cin >> n;
    for(int i = 0; i < n; i++) cout << v[i] << " ";
}