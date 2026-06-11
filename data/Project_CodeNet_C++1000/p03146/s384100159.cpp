#include<bits/stdc++.h>
using namespace std;
int fa(int a){
    if(a%2==0){
        return a/2;
    }
    else{
        return 3*a+1;
    }
}
int main(){
    int s;
    cin>>s;
    set<int> S;
    int sum=0;
    while(!S.count(s)){
        S.insert(s);
        s=fa(s);
        sum++;
    }
    cout<<sum+1<<endl;
}