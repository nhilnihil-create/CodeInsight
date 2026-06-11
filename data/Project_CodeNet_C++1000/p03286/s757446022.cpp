#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t n;
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }
    int64_t i=1;

    vector<int> s(0);//s.at(i)は-2のi乗の位
    for(int64_t j=0;n!=0;j++){
        if(n%(i*2)!=0){
            s.push_back(1);
            n-=pow(-2,j);
        }
        else s.push_back(0);
        i*=(-2);
    }
    int64_t m=s.size();
    for(int64_t j=0;j<m;j++){
        cout<<s.at(m-j-1);
    }
}