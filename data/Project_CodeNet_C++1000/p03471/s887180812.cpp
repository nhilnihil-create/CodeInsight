#include <iostream>
using namespace std;
int main(){
    int n, y;
    cin >> n >> y;
    for(int m=0; m<=n; m++){
        for(int g=0; g<=n-m; g++){
            if(10000*m+5000*g+1000*(n-m-g)==y){
                cout << m << " " << g << " " << n-m-g << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}