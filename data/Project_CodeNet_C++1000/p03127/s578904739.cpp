#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    if(a < b) swap(a, b);
    int r;
    while(r = a % b){
        a = b;
        b = r;
    }
    return b;
}

int main(){
    int n;
    cin >> n;
    int ans, a;
    cin >> ans;
    for(int i = 0; i < n-1; i++){
        cin >> a;
        ans = gcd(ans, a);
    }

    cout << ans << endl;

    

}