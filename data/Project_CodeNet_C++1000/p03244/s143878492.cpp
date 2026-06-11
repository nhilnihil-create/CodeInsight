#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main(){
    int n;
    cin >> n;
    vector<int> V(n);
    for(int i=0; i<n; i++) cin >> V[i];

    vector<int> A(100010);
    vector<int> B(100010);
    for(int i=0; i<n; i++){
        if (i%2==0) A[V[i]]++;
        else B[V[i]]++;
    }

    int max_a=0, max_b=0;

    max_a = max_element(A.begin(), A.end()) - A.begin();
    max_b = max_element(B.begin(), B.end()) - B.begin();


    if (max_a != max_b){
        cout << (n/2-A[max_a]) + (n/2-B[max_b]) << endl;
    }else{
        sort(A.rbegin(), A.rend());
        sort(B.rbegin(), B.rend());
        cout << min((n/2-A[0]) + (n/2-B[1]), (n/2-A[1]) + (n/2-B[0])) << endl;
    }
    return 0;
}