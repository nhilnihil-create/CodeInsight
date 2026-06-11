#include<bits/stdc++.h>
using namespace std;

int solve(int a, int b){
    //Escolhe o maior dentre os 3 cenários possíveis
    return max({2*a-1, 2*b-1, a+b});
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<solve(a,b)<<endl;

    return 0;
}