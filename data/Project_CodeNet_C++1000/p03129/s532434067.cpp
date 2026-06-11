#include <iostream>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    if(n%2==0){
        if(n/2 >= k){
            puts("YES");
        }else{
            puts("NO");
        }
    }else{
        if(n/2+1 >= k){
            puts("YES");
        }else{
            puts("NO");
        }
    }
    return 0;
}