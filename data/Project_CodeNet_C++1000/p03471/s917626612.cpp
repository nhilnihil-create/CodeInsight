#include <iostream>

using namespace std;
int main(){
    int i,j,n,y; cin >> n >> y;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            int k = n - i - j;
            if(k<0) continue;
            if(1000*k + 5000*j + 10000*i==y){
                cout << i << " " << j << " " << k  << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " "<< -1 << endl;
}