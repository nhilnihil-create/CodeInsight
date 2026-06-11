#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
    int n;
    cin >> n;
    if(n==10 || n==100 || n==1000 || n==10000 || n==100000)cout << 10 << endl;
    else{
        int ans=0;
        ans+=n/100000;
        n%=100000;
        ans+=n/10000;
        n%=10000;
        ans+=n/1000;
        n%=1000;
        ans+=n/100;
        n%=100;
        ans+=n/10;
        n%=10;
        ans+=n;
        cout << ans << endl;
    }
}



    
   
