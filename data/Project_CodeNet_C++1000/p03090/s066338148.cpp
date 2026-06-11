#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 1e3 + 3;

signed main(){
    int n;
    cin >> n;
    cout << n * (n-1) / 2 - n/2 << endl;
    int h = !(n & 1);
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++){
            if(j == n-i+h) continue;
            cout << i << " " << j << endl;
        }
    
    return 0;
}