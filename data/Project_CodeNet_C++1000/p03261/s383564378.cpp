#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string A[N];
    set <string> values;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    for (int i=0; i<N-1; i++){
        if (A[i].at(A[i].length()-1)!=A[i+1].at(0)){
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i=0; i<N; i++){
        values.insert(A[i]);
    }
    if (values.size()!=N) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}