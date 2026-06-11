//Bulletin Board
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    int num2=0;
    if(N/1000==2)num2++;
    if(N/100%10==2)num2++;
    if(N/10%10==2)num2++;
    if(N%10==2)num2++;
    cout<<num2<<endl;
    return 0;
}