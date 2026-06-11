#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(4*i+7*j == n){
                puts("Yes");
                return 0;
            }
        }
    }
    puts("No");
    return 0;
}