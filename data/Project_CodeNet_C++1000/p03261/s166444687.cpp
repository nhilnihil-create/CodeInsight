#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    
    vector<string> A(N);
    
    for(int i=0;i<N;i++) cin >> A[i];
    
    bool can = true;
    for(int i=0;i<N-1;i++){
       // cout << A[i][0] << endl;
        if(A[i][A[i].size()-1]!=A[i+1][0]) can = false;
    }
    sort(A.begin(),A.end());
    
    for(int i=0;i<N-1;i++){
        if(A[i]==A[i+1]) can = false;
    }
    
    if(can) cout << "Yes";
    else cout << "No";
    return 0;
}
