#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 1e5 + 5;

int i,n,a,b,t,x,k;

signed main(){
    cin >> n >> a >> b;
    if(n < a+b-1 || n > 1LL*a*b){
        cout << -1;
        return 0;
    }
    
    for(t = n, k=0; t+k > b ; k++){
        x = min(a , t+k+1-b);
        for(i=t-x+1; i<=t; i++)
            cout << i << " ";
        t -= x;
     }
     
     for(; t ; t--) cout << t << " ";
    return 0;
}