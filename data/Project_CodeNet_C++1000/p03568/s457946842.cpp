#include<bits/stdc++.h>
using namespace std;

int main(){
    int N=0,i=0,odd=0,even=0,san=1,ni=1;
    cin >> N;
    int A[N]={};
    for(i=0;i<N;i++){
        san *=3;
        cin >> A[i];
        if(A[i]%2==0)even++;
        else odd++;
    }
    for(i=0;i<even;i++){
        ni *= 2;
    }   
    cout << san - ni << endl;
    return 0;
}