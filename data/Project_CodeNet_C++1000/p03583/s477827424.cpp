#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long N;
    cin >> N;
    for(long long i = 1; i <= 3500; i++){
        for(long long j = 1; j <= 3500; j++){
            long long t = i * j * N;
            long long s = 4 * i * j - N * (i + j);
            if(s != 0 && t % s == 0 && t / s > 0){
                long long w = t / s;
                cout << i << ' ' << j << ' ' << w << endl;
                return 0;
            }
        }
    }
}