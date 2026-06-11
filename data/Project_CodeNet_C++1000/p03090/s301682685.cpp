#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n, m, k;
    vector< vector<int> > edg;
    cin >> n;
    m = n/2;
    k = m * (m-1) * 2;
    if(n%2 == 1) k += m * 2;

    cout << k << endl;

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(i+j != m*2+1){
                cout << i << " " << j << endl;
            }
        }
    }
}
