#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    int min = 1000000000;
    rep(i, n){
        cin >> vec[i];
        int num = 0;
        while(vec[i] % 2 == 0){
            vec[i] /= 2;
            num++;
            if(num > min) break;
        }
        
        if(min > num) min = num;
    }
    
    cout << min << endl;
    
}