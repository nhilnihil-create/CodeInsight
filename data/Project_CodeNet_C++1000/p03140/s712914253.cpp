#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    string A,B,C;
    int N;
    cin  >> N >> A >> B >> C;
    ll count = 0;
    for(int i=0;i<N;i++){
        if(A[i]!=B[i]&&A[i]!=C[i]&&B[i]!=C[i]){
            count += 2;
        }else if(A[i]==B[i]&&A[i]!=C[i]||A[i]==C[i]&&A[i]!=B[i]||C[i]==B[i]&&A[i]!=B[i]){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}