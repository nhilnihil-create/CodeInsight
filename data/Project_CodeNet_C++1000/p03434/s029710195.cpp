#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];

    sort(A.begin(), A.end(), greater<int>());

    int alice_score = 0, bob_score = 0;
    
    for(int i = 0; i < n; i++){
        if(i%2)
            bob_score += A[i];
        else
            alice_score += A[i];     
    }
    int final_ans = alice_score - bob_score;    
        cout<<final_ans;

return 0;
}
