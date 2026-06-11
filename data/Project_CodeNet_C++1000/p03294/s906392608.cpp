#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

    int N,A,ans=0; cin >> N;
 
    for(int i=0;i<N;i++){cin >> A;  ans+=(A-1);}
    cout << ans << endl;
}