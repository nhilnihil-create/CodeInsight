#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    int k;
    cin >> k;
    if(k%2 == 0){
        cout << (k/2)*(k/2) << endl;
    }    
    else cout << (k/2)*((k+1)/2);
}