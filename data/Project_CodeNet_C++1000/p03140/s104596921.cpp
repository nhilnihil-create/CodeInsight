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
    int N, i, ans=0;
    string A, B, C;

    cin >> N >> A >> B >> C;
    
    for(i=0; i<N; i++){
        if(A[i]!=B[i] && B[i]!=C[i] && C[i]!=A[i]){
            ans += 2;
        }
        else if(A[i]==B[i] && B[i]!=C[i]){
            ans += 1;
        }
        else if(A[i]==C[i] && B[i]!=C[i]){
            ans += 1;
        }
        else if(B[i]==C[i] && A[i]!=C[i]){
            ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}