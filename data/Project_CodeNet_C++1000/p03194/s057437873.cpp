#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long int n, p, c, d, ans=1;
    cin >> n >> p;
    for(int i=2; i<=(int)sqrt(p); i++){
        c=0;
        d=p;
        while(d%i==0 && c<n){
            d=d/i;
            c++;
        }
        if(c==n){
            ans=i;
        }
    }
    if(n==1){
        ans = p;
    }
    cout << ans << endl;
}