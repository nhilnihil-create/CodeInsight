#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> vec;
    if(n==0){
        cout << 0 << endl;
        return 0;
    }
    long long i=2,k=1;
    while(n!=0){
        if(n>0&&i>0){
            if(n%i==k){
            vec.push_back(1);
            n-=k;
            }
            else{
            vec.push_back(0);
            }
        }
        else if(n<0&&i>0){
            if((-1*n)%i==k){
            vec.push_back(1);
            n-=k;
            }
            else{
            vec.push_back(0);
            }
        }
        else if(n>0&&i<0){
            if((-1*n)%i==k){
            vec.push_back(1);
            n-=k;
            }
            else{
            vec.push_back(0);
            }
        }
        else if(n<0&&i<0){
            if(n%i==k){
            vec.push_back(1);
            n-=k;
            }
            else{
            vec.push_back(0);
            }
        }
        i*=-2;
        k*=-2;
    }
    for(int i=vec.size()-1;i>=0;i--){
        cout << vec[i];
    }
    cout << endl;
}