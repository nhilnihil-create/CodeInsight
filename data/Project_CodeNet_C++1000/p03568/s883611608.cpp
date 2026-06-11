#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    long long count = round(pow(3, N));
    long long odd_count = (A[0] % 2 == 0)? 2 : 1;

    for(int i=1; i<N; i++){
        if(A[i] % 2 == 0){
            odd_count *= 2;
        }else{
            count *= 1;
        }
    }

    cout << count - odd_count << endl;
    return 0;

}