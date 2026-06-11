#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    string x;
    cin >> x;
    int N = x.size();
    vector <char> f(N);
    int res;
    for(int bit = 0; bit < (1<<N); ++bit){
        res = x[0] - '0';
        for(int i = 1; i < N; i++){
            if(bit & (1<<i)) {
                res -= x[i] - '0';
                f[i] = '-';
            }
            else {
                res += x[i] - '0';
                f[i] = '+';
            }
        
        }
        if(res == 7){
            break;
        }
    }
    cout << x[0] << f[1] << x[1] << f[2] << x[2] << f[3] << x[3] << "=7" << endl;;
    return 0;
}