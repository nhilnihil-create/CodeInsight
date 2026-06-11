#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int A,B,C;
    int count=0;
    cin>>A>>B>>C;
    if(C>=1+(A+B)){
        count+=(A+B)+1+B;
    }
    else{
        count+=(B+C);
    }
    cout<<count;
return 0;
}