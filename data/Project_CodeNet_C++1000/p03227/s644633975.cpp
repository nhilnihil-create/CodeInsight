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

    string str;
    cin >> str;

    if(str.size() == 3){
        for(int i=2; i>=0; i--){
            cout << str[i];
        }
        cout << endl;
    }else{
        cout << str << endl;
    }

    return 0;
}