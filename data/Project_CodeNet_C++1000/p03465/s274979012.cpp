#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    bitset<2000*2000+1> bits;
    bits[0] = 1;
    for(int a : A) bits |= bits<<a;
    int S = accumulate(A.begin(), A.end(), 0);
    for(int i=(S+1)/2; i<=S; i++) if(bits[i]){
        cout << i << endl;
        return 0;
    }
}