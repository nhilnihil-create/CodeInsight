#include<iostream>
using namespace std;
int main(){
    int n,y;
    cin >> n >> y;
    int res10000 = -1, res5000 = -1, res1000 = -1;
    for(int a = 0;a <= n;++a){
        for(int b = 0;b + a <= n;++b){
            int c = n - a - b;
            int total = a * 10000 + b * 5000 + c * 1000;
            if (total == y) {
                res10000 = a;
                res5000 = b;
                res1000 = c;
            }
        }
    }
    cout << res10000 << " " << res5000 << " " << res1000 << endl;
}