#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int64_t N, A, B;
    cin >> N >> A >> B;
    if(N < A+B-1 || A*B < N){
        cout << -1 << endl;
        return 0;
    }

    vector<int> num(B, 1);
    num[B-1] = A;
    int rest = N-(A+B-1);
    while(rest) for(int i=0; i<B-1; i++) if(rest) num[i]++, rest--;

    vector<vector<int>> ans(B);
    int pt = 1;
    for(int i=B-1; i>=0; i--) for(int j=0; j<num[i]; j++) ans[i].push_back(pt++);
    for(int i=0; i<B; i++) for(int a : ans[i]) cout << a << " ";
    cout << endl;
}