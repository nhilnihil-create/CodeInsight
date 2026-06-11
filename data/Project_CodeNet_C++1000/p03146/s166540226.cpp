#include "./bits/stdc++.h"
using namespace std;

vector<int> A;
// int index=0;
int ans=0;
bool flag;

bool check(int num){
    for(int i=0;i<A.size();i++){
        if(A[i]==num){
            ans = A.size()+1;
            return true;
        }
    }
    return false;
}

int main(){
    int s;
    cin >> s;
    A.push_back(s);
    while(1){
        if(s%2==0){
            int a=s/2;
            if(check(a)){
                break;
            }
            A.push_back(a);
            // cout << a << endl;
            s=a;
        }else{
            int b=3*s+1;
            if(check(b)){
                break;
            }
            A.push_back(b);
            // cout << b << endl;
            s=b;
        }
    }
    cout << ans << endl;
    return 0;
}