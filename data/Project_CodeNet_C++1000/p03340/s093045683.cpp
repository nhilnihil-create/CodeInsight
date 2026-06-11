// Xor sum 2
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>
#define lint unsigned long long int
#define FOR(x, to) for(int x=0; x<(int)(to); x++)
#define DUMP(ar) for(auto itd=begin(ar); itd != end(ar); itd++) cout << "["s << itd - begin(ar) << "]:"s << *itd << endl
#define DUMPL(ar) for(auto itd=begin(ar); itd != end(ar); itd++) { cout << *itd; if(end(ar)-itd > 1) cout << ' '; } cout << endl
#define COUT(x) cout << (x) << endl
#define VCIN(ar) for(auto &vcin: (ar)) cin >> vcin
#define ALL(ar) ar.begin(), ar.end()
#define LOOPD(i) cout << "ループ["s << i << "]回目---------------"s << endl
using namespace std;
// lint:64ビット 10^19

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    VCIN(a);

    int right, left = 0;
    lint xor_sum = 0;
    lint ans = 0;
    for(right=0; right<n; right++){
        ans++;
        if((xor_sum ^ a[right]) == xor_sum + a[right]){
            xor_sum = xor_sum + a[right];
        }else{
            while(true){
                xor_sum = xor_sum ^ a[left++];
                if((xor_sum ^ a[right]) == xor_sum + a[right]){
                    break;
                }
            }
            xor_sum = xor_sum + a[right];
        }

        // cout << "[l-r]: " << left << ' ' << right << " xor: " << xor_sum << endl;
        ans += right - left;
    }
    
    COUT(ans);

    return 0;
}