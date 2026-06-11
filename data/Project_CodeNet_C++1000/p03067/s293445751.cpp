#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,s,d;
    cin >>a>>s>>d;
    if((a<=d)&&(d<=s)){
        cout << "Yes" <<endl;
    }
    else if((s<=d)&&(d<=a)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" <<endl;
    }

    return 0;
}
