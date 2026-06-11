#include <iostream>

using namespace std;
int main(){
    int n,i,max,sum;
    while (cin >> n){
        int sides[n];
        max = 0;
        sum = 0;
        for(i = 0; i < n; i++){
            cin >> sides[i];
            sum += sides[i];
            if(sides[i] > max) max = sides[i];
        }
        if (2*max < sum) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}