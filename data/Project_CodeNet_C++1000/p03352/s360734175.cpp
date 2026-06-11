#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    if(n==1){
        cout << "1\n";
    }
    else{
        int i, j;
        int tmp = 0, res = 0;
        for(i=2; i<=n; i++){
            for(j=2; j<=n; j++){
                tmp = pow(i, j);
                if(tmp>n){
                    break;
                }
                else{
                    res = max(res, tmp);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}