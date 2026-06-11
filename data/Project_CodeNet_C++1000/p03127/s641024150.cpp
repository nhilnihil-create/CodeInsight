#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    
    int amari = a[0];
    while(1){
        bool isconst = true;
        for(int i = 0; i < n; i++){
            if(a[i] % amari != 0){
                amari = a[i] % amari;
                a[i] = amari;
                isconst = false;
            }
        }
        if(isconst) break;
    }
    cout << amari << endl;
}