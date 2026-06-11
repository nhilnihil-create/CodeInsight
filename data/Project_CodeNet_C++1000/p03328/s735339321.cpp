#include <bits/stdc++.h>
#define rep(i,n) for(int i=1;i<n;i++)
using namespace std;
using ll=long long;
using P = pair<int,int>;
int main(){
    int A[1000];
    A[0]=0;
    for(int i=1;i<1000;i++){
        A[i]=A[i-1]+i;
    }
    int a,b;
    cin >> a >> b;
    int s=b-a;
    cout << A[s]-b << endl;
}