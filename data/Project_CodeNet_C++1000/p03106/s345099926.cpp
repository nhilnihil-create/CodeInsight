#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, K;
    cin >> A >> B >> K;
    vector<int> Ks(max(A,B));
    int i = 1;
    while (i <= max(A,B) ){
        if (A%i == 0 && B%i == 0){
            Ks.push_back(i);
        }
        i += 1;
    }
    reverse(Ks.begin(), Ks.end());
    cout << Ks.at(K-1) << endl;
}