#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main(void)
{
    ll N, i, j, judge=1;

    cin >> N;

    vector<ll> a, b(N);

    for(i=0; i<N; i++){
        cin >> b[i];
    }

    while(b.size() >= 1){
        for(i=b.size()-1; i>=0; i--){
            if(b[i] == i+1){
                a.push_back(b[i]);
                b.erase(b.begin()+i);
                break;
            }
            if(i==0){
                judge = 0;
                break;
            }
        }
        if(judge==0) break;
    }

    if(judge==1){
        for(i=a.size()-1; i>=0; i--){
            cout << a[i] << endl;
        }
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}