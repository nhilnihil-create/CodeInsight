#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ALL(x) x.begin(), x.end() 
int main(){
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<long long> A(X), B(Y), C(Z);
    for(int i = 0; i < X; i++) cin >> A[i];
    for(int i = 0; i < Y; i++) cin >> B[i];
    for(int i = 0; i < Z; i++) cin >> C[i];
    vector<long long> sumab;
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            long long temp = A[i] + B[j];
            sumab.push_back(temp);
        }
    }
    sort(ALL(sumab));
    sort(ALL(C));
    long long ub = 1e18, lb = 0;
    long long iki;
    while(ub - lb > 1){
        long long ko = 0;
        long long mid = (ub + lb) / 2;
        for(int i = 0; i < Z; i++){
            long long cnt = sumab.end() - lower_bound(ALL(sumab), mid - C[i]);
            ko += cnt;
        }
        if(ko > K) lb = mid;
        else ub = mid;
    }
    vector<long long> ans; 
    long long kosu = X * Y;
    int flag = 0;
    for(int i = Z - 1; i >= 0; i--){
        for(int j = X * Y - 1; j >= 0; j--){
            long long temp = C[i] + sumab[j];
            if(temp < ub){
                if(j == X * Y - 1) flag = 1;
                break;
            }
            ans.push_back(temp);
        }
        if(flag == 1) break;
    }
    sort(ALL(ans));
    for(int i = 0; i < K; i++){
        if(i < ans.size()) cout << ans[(int)ans.size() - 1 - i] << endl;
        else cout << lb << endl;
    }
}