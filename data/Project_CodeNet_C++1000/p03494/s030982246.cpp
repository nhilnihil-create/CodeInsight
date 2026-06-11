#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int i;
    int N;
    int count=0;
    cin >> N;
    int A[N];
    for(i=0;i<N;i++){
        cin >>A[i];
    }
    bool flag = true;
    while(flag){
        for(i=0; i<N; i++){
            if(A[i]%2 == 1){
                flag = false;
                break;
            }
            A[i]=A[i]/2;
        }
        if(flag)count++;
    }

    cout << count << endl;
}