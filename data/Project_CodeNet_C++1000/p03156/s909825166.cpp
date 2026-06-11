#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int N,A,B;
    cin >> N >> A >> B;
    int c;
    int F=0,S=0,T=0;
    for(int i=1;i<=N;i++){
        cin >> c;
        if(c<=A)F++;
        else if(c<=B)S++;
        else T++;
    }
    int ans = min(F,min(S,T));
    cout << ans << endl;
}