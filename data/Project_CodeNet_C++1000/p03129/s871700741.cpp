/*
ID: vantofr1
TASK: friday
LANG: C++

*/
#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define zurbzan
#define MAXPEOPLE 10
using namespace std;
const int MOD = 1e9;
int to_int(string s){
    int x;
    stringstream geek(s);
    geek >> x;
    return x;
}
int prim_const( int x){
    vector<bool> prime(x, true);
    prime[0] = prime[1] = false;
    for (int i=2; i * i<=x; ++i){
        if (prime[i]){
            if (i * 1ll * i <= x){
                for (int j=i*i; j<=x; j+=i){
                    prime[j] = false;
                }
            }
        }
    }
    if (prime[x] == true){
        return 1;
    }else{
        return 0;
    }
}
using namespace std;
unsigned long long int x,y;
int mxn;
int main(){
    double n,k;
    cin >> n >> k;
    if (k >= n && k != 1 && n != 1){
        cout << "NO";
    }else if(ceil(n/2) >= k || n == 1 && k == 1){
        cout << "YES";
        }else{
            cout << "NO";
        }
}
