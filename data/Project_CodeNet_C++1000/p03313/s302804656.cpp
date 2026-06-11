#include <iostream>
#include <vector>
using namespace std;

#define chmax(x, y) x = max(x, y)

int main(void){
    int N;
    cin >> N;
    vector<int> A(1 << N);
    for(int i = 0; i < (1 << N); ++i)   cin >> A[i];
    
    int res = 0;
    for(int K = 1; K < (1 << N); ++K){
        int firstmax = max(A[K], A[0]), secondmax = min(A[K], A[0]);
        int subset = (K - 1) & K;
        while(subset){  // 部分集合列挙
            int hoge = A[subset];
            if(hoge > firstmax)     swap(hoge, firstmax);
            if(hoge > secondmax)    swap(hoge, secondmax);
            subset = (subset - 1) & K;
        }
        chmax(res, firstmax + secondmax);
        cout << res << "\n";
    }
}