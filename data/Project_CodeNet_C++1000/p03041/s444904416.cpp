#include<vector>
#include <iostream>
#include<string>
#include <complex>
#include <algorithm>
#include<string>

using namespace std;

int main(){
    int n, k;
    cin >> n;
    cin >> k;

    char s[n];
    char c;
    for(int i = 0; i< n; i++){
        cin >> c;
        if(i+1 == k){
            c += 32;
        }
        cout << c;
    }

    cout << endl;
}