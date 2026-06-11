#include<iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int s =1;
    int a,b;
    for(int i=0;i<n;i++){
        a = s*2;
        b = s+k;
        if(a<b){
            s=a;
        }else{
            s=b;
        }
    }
    cout << s << endl;
}