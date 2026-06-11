#include <iostream>
#include<vector> 
using namespace std;

int syou(int a){
    if(a>0){
        return a/(-2);
    }else if(a==0){
        return 0;
    }else{
        if(a%2==0){
            return a/(-2);
        }else{
            return (a/(-2))+1;
        }
    }
}

int main(){
    vector<int> v;
    int N,num;
    cin >> N;
    if(N==0){
        cout << 0;
        exit(0);
    }
    while(1){
        num=syou(N);
        if(num==1){
            v.push_back(N - num * (-2));
            v.push_back(1);
            break;
        }
        v.push_back(N-num*(-2));
        N=num;
    }
    for(int i=v.size()-1;i>=0;i--){
        cout << v[i];
    }
}