#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    int N,A,B;
    cin >> N >> A >> B;
    
    int tmp = 0;
    if(A+B<=N) tmp = 0;
    else tmp = abs(N-A-B);
    cout << min(A,B) << " " << tmp << endl;
    
    return 0;
}
