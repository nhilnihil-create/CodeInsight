#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    
    long long K,A,B;
    cin >> K >> A >> B;
    if(K < A)cout << K << endl;
    else if(B-A<=2)cout<< K + 1 <<endl;
    else cout << A +  ((K-A+1)/2)*(B-A)+(K-A+1)%2 <<endl;
    
}

    
    

