#include <iostream>
#include <cmath>

using namespace std;

int main(){
    uint64_t n, p;
    cin >> n >> p;

    uint64_t res=1;
    uint64_t x=2;

    if(n==1){
        res=p;
        goto out;
    }

    while(p!=1 && pow(x, n) <= p){
        bool found=true;
        for(uint64_t i=0; i<n; ++i){
            if(p%x){
                found=false;
                break;
            }
            p/=x;
        }
        if(found){
            res*=x;
            continue;
        }
        ++x;
    }
out:
    cout << res << endl;
    return 0;
}
