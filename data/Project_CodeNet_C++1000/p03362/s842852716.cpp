#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 55556;
bool prime[N];
vector<int> p;
void sieve(){
    memset(prime,1,sizeof(prime));
    for (int i = 2; i < N; ++i)
    {
        if(prime[i])
        {
            if(i%5 == 1)
                p.push_back(i);
            for(int j = 2*i ; j < N; j += i)
                prime[j] = 0;
        }
    }
}
signed main(){
    int t = 1; //cin >> t;
    while(t--){
        int n; cin >> n;
        sieve();
        for(int i = 0; i < n; i++)
            cout << p[i] << " ";
    }    
}