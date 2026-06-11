#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;

int main(){
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        long long a, b;
        cin >> a >> b;
        long long c = (long long)sqrt(a * b);
        if(c * (c + 1) < a * b){
            cout << 2 * c - 1 << endl;
        }else if(c * c == a * b && a != b){
            cout << 2 * (c - 1) - 1 << endl;
        }else{
            cout << 2 * (c - 1) << endl;
        }
    }
    return 0;
}