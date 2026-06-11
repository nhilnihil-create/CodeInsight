#include<iostream>
#include<algorithm>
using namespace std;

long long A[100000], B[100000], ans = 0, m = 1e9;

int main(){
    int N;
    cin >> N;
    bool is_same_set = true;
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
        if(A[i] != B[i]){
            is_same_set = false;
        }
        ans += A[i];
        if(A[i] > B[i] && B[i] < m){
            m = B[i];
        }

    }
    if(is_same_set){
        cout << 0 << endl;
        return 0;
    }
    cout << ans - m << endl;
}
