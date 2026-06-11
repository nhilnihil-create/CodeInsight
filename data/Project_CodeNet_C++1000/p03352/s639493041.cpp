#include <bits/stdc++.h>
using namespace std;
int main(){
    int X;
    cin>> X;
    int Ans=1;
    for(int i=2;i<35;i++){
        int j =2;
        while(pow(i,j)<=X){
            int A = pow(i,j);
            if(A<=X)Ans = max(Ans,A);
            j++;
        }
    }
    cout << Ans << endl;
}