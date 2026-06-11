#include<bits/stdc++.h>
using namespace std;


const int N = 2005, M = 4e6 + 5;



int n, x, sum, a[N];
vector < int > q;
bitset < M > dp;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        sum += x;
        a[x] += 1;
    }
    for(int i = 1; i <= 2000; i++){
        int cur = a[i];
        for(int j = 1; cur > 0; cur -= j, j <<= 1){
            if(j > cur){
                q.push_back(i * cur);
            }
            else{
                q.push_back(i * j);
            }
        }
    }
    dp[0] = 1;
    for(auto it : q){
        dp |= dp << it;
    }
    int i = (sum + 1) / 2;
    while(!dp[i]){
        i += 1;
    }
    cout << i;
}
