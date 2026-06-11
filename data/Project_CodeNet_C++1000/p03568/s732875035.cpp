#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = pow(3, n), m=1, tmp;
    for(int i=0; i<n; i++){
        cin >> tmp;
        if(tmp%2==0){
            m *= 2;
        }
    }
    cout << ans - m << endl;
    return 0;
}