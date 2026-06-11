#include <bits/stdc++.h>
 
using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i< (int) n; i++)
 
 
int main () {

    int N;

    cin >> N;

    int ans = 10000;
    for(int i=1; i <= (N+1)/2; i++ ){
        int a = i;
        int b = N-i;
        int sum = 0;

        while( a> 0){
            sum+= a%10;
            a /= 10;
        }
        
        while( b> 0){
            sum+= b%10;
            b /= 10;
        }

        ans = min(ans,sum);

    }
     cout << ans << endl;


}
