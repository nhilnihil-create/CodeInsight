#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, n)for(int i=0; i<n; i++)
using namespace std;

int main(){
    int a, b, k;
    vector<int> divisor;
    cin >> a >> b >> k;
    int j=0;
    for(int i=1; i<=a || i<=b; i++){
        if(a%i==0 && b%i==0){
            divisor.push_back(i);
            j++;
        }
    }

    reverse(divisor.begin(), divisor.end());
    cout << divisor[k-1] << endl;

    return 0;
}
