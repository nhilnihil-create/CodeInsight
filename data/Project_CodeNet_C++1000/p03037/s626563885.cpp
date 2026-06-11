#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    long long left = 1, right = n;

    for(long long i = 0; i < m; i++){
        long long l, r;
        cin >> l >> r;
        if(l > right){
            printf("0\n");
            return 0;
        }
        else if(r < left){
            printf("0\n");
            return 0;
        }

        if(left < l){
            left = l;
        }

        if(right > r){
            right = r;
        }
        //printf("left %lld right %lld\n", left, right);  
    }
    

    cout << right - left + 1 << endl;

    return 0;
}