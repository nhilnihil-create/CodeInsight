#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin >> n>>a>>b;
    if(a>=b){
        cout << b << endl;
    }
    else{
        cout << a << endl;
    }

    if((a+b-n)<0){
        cout << 0 << endl;
    }
    else{
        cout << a+b-n<<endl;
    }

    return 0;
}