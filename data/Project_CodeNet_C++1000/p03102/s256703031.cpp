#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, c, count=0, ans=0;
    cin >> n >> m >> c;
    vector<int> B(m);
    for(int i = 0; i < m; i++){
        cin >> B[i];
    }
    vector<int> A(m);
    for(int j = 0; j < n; j++){
        for(int i = 0; i < m; i++){
            cin >> A[i];
        }
        for(int i = 0; i < m; i++){
            ans += A[i] * B[i];
        }
        ans += c;
        if(ans > 0)
            count++;
        ans = 0;         
    }
    cout << count;
    return 0; 
}