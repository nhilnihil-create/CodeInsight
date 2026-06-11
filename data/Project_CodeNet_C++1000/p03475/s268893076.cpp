#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;

int main(){
    int n;  cin >> n;

    vector<ll> c(n, 0), s(n, 0), f(n, 0);
    for(int i=0; i<n-1; i++)
        cin >> c[i] >> s[i] >> f[i];
        
    for(int i=0; i<n; i++){
        ll sum = 0;
        for(int j=i; j<n-1; j++){
           if(sum<s[j]) sum = s[j];
           else if((sum-s[j])%f[j]>0) sum += f[j]-(sum-s[j])%f[j];
            sum += c[j]; 
        }
        
        cout << sum << endl;
    }
    
    
}