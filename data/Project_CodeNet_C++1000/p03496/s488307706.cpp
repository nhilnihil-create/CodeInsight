#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    int mn = 0, mx = 0;
    int mni = -1, mxi = -1;
    int A[N+3];
    for(int i = 0; i < N; ++i) {
        cin >> A[i]; 
        if(A[i] < mn) { mni = i + 1; mn = A[i]; }
        else if(A[i] > mx) { mxi = i + 1; mx = A[i]; }
    }

    if(mni == -1) {
        cout << N-1 << endl;
        for(int i = 1; i < N; ++i)
            cout << i << " " << i + 1 << endl;
    } else {
        if(mxi == -1) {
            cout << N-1 << endl;
            for(int i = N; i > 1; --i) 
                cout << i << " " << i - 1 << endl;
        }
        else if(abs(mx) >= abs(mn)) {
            cout << 2*N-2 << endl;
            for(int i = 1; i <= N; ++i) 
                if(i != mxi) 
                    cout << mxi << " " << i << endl;
            for(int i = 1; i < N; ++i) 
                cout << i << " " << i + 1 << endl;
        }
        else {
            cout << 2*N-2 << endl;
            for(int i = 1; i <= N; ++i) 
                if(i != mni)
                    cout << mni << " " << i << endl;
            for(int i = N; i > 1; --i) 
                cout << i << " " << i - 1 << endl;
        }
    }

    return 0;
}