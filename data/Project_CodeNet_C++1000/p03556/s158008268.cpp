#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0;;i++){
        double memo = sqrt(n - i);
        int memo2 = sqrt(n - i);
        if(memo - memo2 == 0){
            cout << n - i << endl;
            break;
        }
    }
}