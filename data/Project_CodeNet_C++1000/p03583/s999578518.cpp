#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;
 
int main()
{
    ll N;  cin >> N;
    ll i, j, k, a, b, tmp;
    for(ll i=1; i<=3500; i++){
        for(ll j=1; j<=3500; j++){
          	tmp = N*i*j;
            a = 4*i*j;
            b = N*(i+j);
            if(a > b){
                if(tmp % (a-b) == 0){
                    k = tmp / (a-b);
                    cout << i << " " << j << " " << k << endl;
                    return 0;
                }
            }
        }
    }
}