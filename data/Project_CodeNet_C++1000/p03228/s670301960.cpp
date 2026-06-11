#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#define lint long long int
#define FOR(x, to) for(int x=0; x<(int)(to); x++)
#define DUMP(ar) for(int loop_dump=0; loop_dump<(int)ar.size(); loop_dump++) cout << "[" << loop_dump << "]:" << ar[loop_dump] << endl
#define DUMPL(ar) for(int loop_dump=0; loop_dump<(int)ar.size(); loop_dump++) { cout << ar[loop_dump]; if(loop_dump<(int)ar.size()-1) cout << ' '; } cout << endl;
#define COUT(x) cout << x << endl
#define ALL(ar) ar.begin(), ar.end()
#define LOOPD(i) cout << "ループ[" << i << "]回目---------------" << endl
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, k;
    cin >> a >> b >> k;
    for(int i=0; i<k; i++){
        if(i % 2 == 0){
            if(a % 2 == 1){
                a--;
            }
            b += a /= 2;
        }else{
            if(b % 2 == 1){
                b--;
            }
            a += b /= 2;
        }
    }

    cout << a << ' ' << b << endl;

    return 0;
}