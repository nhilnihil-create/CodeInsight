#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1000000000; //10^9

int main(){
    int N, x;
    cin >> N >> x;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(),A.end());
    int ans = 0;
    for(int j = 0; j < N; j++){
        if (j == N - 1 && (A.at(j) - x) != 0){
            break;
        }
        if(A.at(j) <= x){
            x -= A.at(j);
            ans++;
        }else{
            break;
        }
    }
    cout << ans << endl;
}
