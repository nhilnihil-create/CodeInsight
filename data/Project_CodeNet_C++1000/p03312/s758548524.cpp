#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    while(cin >> N){
        vector<long long> A(N);
        for(auto& t : A) cin >> t;
        int b = 0, c = 1, d = 2, e = 3;
        long long sumB = A[0], sumC = A[1], sumD = A[2], sumE = A[3];
        for(int i=4;i<N;i++) sumE += A[i];
        while(e < N-1){
            if(sumD + A[e] > sumE - A[e]) break;
            sumD += A[e];
            sumE -= A[e];
            e++;
        }
        long long res = (1LL << 60);
        while(true){
            for(int i=0;i<2;i++){
                if(c+i == d) continue;
                for(int j=0;j<2;j++){
                    if(e+j == N) continue;
                    long long B = sumB + (i == 0 ? 0 : A[c]);
                    long long C = sumC - (i == 0 ? 0 : A[c]);
                    long long D = sumD + (j == 0 ? 0 : A[e]);
                    long long E = sumE - (j == 0 ? 0 : A[e]);
                    long long M = max(max(B, C), max(D, E));
                    long long m = min(min(B, C), min(D, E));
                    res = min(res, M-m);
                }
            }
            sumC += A[d];
            sumD -= A[d];
            d++;
            if(d == N-1) break;
            while(e < N-1){
                if(d != e && sumD + A[e] > sumE - A[e]) break;
                sumD += A[e];
                sumE -= A[e];
                e++;
            }
            while(c < d-1){
                if(sumB + A[c] > sumC - A[c]) break;
                sumB += A[c];
                sumC -= A[c];
                c++;
            }
        }
        cout << res << endl;
    }
}