#include<iostream>
#include<bitset>
using namespace std;
int n, i, sum;
int v[2005];
bitset<2000002> d;
int main(){
    cin>> n;
    for(i = 1; i <= n; i++){
        cin>> v[i];
        sum += v[i];
    }
    d[0] = 1;
    for(i = 1; i <= n; i++){
        d |= (d << v[i]);
    }
    for(i = sum / 2; i >= 0; i--){
        if(d[i] == 1){
            cout<< sum - i;
            break;
        }
    }
}
