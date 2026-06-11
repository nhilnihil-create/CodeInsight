#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int A[100000];
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A, A+N);
    int *ptr;
    if(N == 2){
        cout << A[1] << ' ' << A[0] << endl;
    }else{
        if(A[N-1]%2 == 0){
            ptr = lower_bound(A, A+N, A[N-1]/2);
            if(*ptr - A[N-1]/2  > A[N-1]/2 - *(ptr-1)) cout << A[N-1] << ' ' << *(ptr-1) << endl;
            else cout  << A[N-1] << ' ' << *ptr << endl;  
        }else{
            
            ptr = lower_bound(A, A+N, (A[N-1]-1)/2);
            
            if((*ptr)*2 - A[N-1]  > A[N-1] - (*(ptr-1))*2) cout << A[N-1] << ' ' << *(ptr-1) << endl;
            else cout  << A[N-1] << ' ' << *ptr << endl;
        }
    }
}
