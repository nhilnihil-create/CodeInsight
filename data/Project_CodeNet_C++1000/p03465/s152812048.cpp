#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    int sum = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    bitset<2002000> bs;
    bs[0] = true;
    for (int i = 0; i < N; i++) {
        bs |= (bs << A[i]); 
    }
    int ans = (sum+1)/2;
    while (!bs[ans])ans++;
    cout << ans << endl;
    return 0;
}
