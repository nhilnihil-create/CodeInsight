#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void){
    int n,m,x;
    cin >> n >> m >> x;
    int A[n+1],B[n+1]={};
    for(int i=0;i<m;i++){
        cin >> A[i];
        B[A[i]] = 1;
    }
    int p=0,q=0;
    for(int i=x;i<n+1;i++){
        if(B[i]==1){
            p++;
        }
    }
    for(int i=x;i>0;i--){
        if(B[i]==1){
            q++;
        }
    }
    cout << min(p,q) << endl;
	return 0;
}