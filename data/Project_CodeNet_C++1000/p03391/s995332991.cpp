#include <vector>
#include <iostream>
using namespace std;
using ll = long long int;
 
int main(){
    int n; cin >> n;
    int min_b = 1e9 + 10;
    ll total = 0;
    bool anydiff = false;
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        total += a;
        if(a > b){
            min_b = min(min_b, b);
        }
        if(a != b){
            anydiff = true;
        }
    }
    if(anydiff){
        cout << total - min_b << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}