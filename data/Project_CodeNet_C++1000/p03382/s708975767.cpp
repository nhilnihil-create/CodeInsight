#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int INF = 1LL << 30;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0;i < N;i++)cin >> A[i];
    sort(A.rbegin(),A.rend());
    int mindif = INF;
    for(int i = 1;i < N;i++){
        if(mindif > max(A[0]-A[i],A[i])){
            mindif = A[i];
        }
    }   
    cout << A[0] << " " << mindif << endl;
}