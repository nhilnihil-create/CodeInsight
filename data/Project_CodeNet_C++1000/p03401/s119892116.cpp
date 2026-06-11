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

template <class T> void swap(T& a, T& b) { T t = std::move(a); a = std::move(b); b = std::move(t); }

int main(void)
{
    ll N, i, A[100001], sum=0;

    cin >> N;

    A[0] = 0;

    for(i=1; i<=N; i++){
        cin >> A[i];
    }

    sum += abs(A[1]);
    for(i=2; i<=N; i++){
        sum += abs(A[i-1]-A[i]);
    }
    sum += abs(A[N]);

    for(i=1; i<=N; i++){
        if(i<=N-1){
            cout << sum-abs(A[i-1]-A[i])-abs(A[i]-A[i+1])+abs(A[i-1]-A[i+1]) << endl;
        }
        else{
            cout << sum-abs(A[N-1]-A[N])-abs(A[N])+abs(A[N-1]) << endl;
        }
    }

    return 0;
}