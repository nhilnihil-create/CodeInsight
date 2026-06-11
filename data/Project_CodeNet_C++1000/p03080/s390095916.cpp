#include<bits/stdc++.h>
using namespace std;
int main(){
    string Answer="No";
    int N,Red=0;
    char input;
    scanf("%d",&N);
    for(int i=0; i<=N; i++){
        if((input=getchar())=='R') Red++;
    }
    if(2*Red-N>0) Answer="Yes";
    cout<<Answer;
    return 0;
}