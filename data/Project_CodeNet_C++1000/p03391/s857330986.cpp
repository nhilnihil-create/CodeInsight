#include <iostream>

#define N_MAX 200000

using namespace std;

int main(){
    int N;
    int diff_max = 0;
    int min_b = 1000000001;
    int diff_max_index;
    long sum = 0;
    int A[N_MAX], B[N_MAX];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        sum += A[i];
    }
    for(int i = 0; i < N; i++){
        if(A[i] > B[i]){
            diff_max = max(diff_max, A[i] - B[i]);
            min_b = min(min_b, B[i]);
        }
    }
    if(diff_max == 0){
        cout << 0 << endl;
    }else{
        cout << sum - min_b << endl;
    }
    
}