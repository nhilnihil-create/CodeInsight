#include <bits/stdc++.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    int B[N];
    for(int i=0; i<N; i++){
        int r =0;
        int counter = 0;
        while(true){
            r = A[i] % 2;
            if(r==1){
                break;
            }
            A[i] = A[i]/2;
            counter += 1;
        }
        B[i] = counter;
    }

    int ans = *min_element(B, B+N);
    cout << ans << endl;
    return 0;
}
