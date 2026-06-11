#include<bits/stdc++.h>
using namespace std;

string solve(int a, int b, int c, int d, int e, int k){
    return (min({a-b,a-c,a-d,a-e,b-c,b-d,b-e,c-d,c-e,d-e}) * (-1)) > k ? ":(" : "Yay!";
    //multipliquei por -1 pro número sempre retornar positivo se min for negativo
}
int main(){
    int a,b,c,d,e,k;
    cin>>a>>b>>c>>d>>e>>k;
    cout<<solve(a,b,c,d,e,k)<<"\n";
    return 0;
}
