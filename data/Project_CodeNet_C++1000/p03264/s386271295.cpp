#include <iostream>
using namespace std;

int main(void){
    int k, ans=0;
    cin >> k;
    for (int i=1; i<k; i++){
        for (int j=i+1; j<=k; j++){
            if ((i%2 == 0 && j%2 == 1) || (i%2 == 1 && j%2 == 0)) ans++; 
        }
    }
    cout << ans << endl;
    return 0;
}