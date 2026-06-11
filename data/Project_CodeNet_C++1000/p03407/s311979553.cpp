#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //vector<string> v = {"ABC"};
    int a,b,c;
    cin>>a>>b>>c;
    if(a+b==c || a+b>c){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}
