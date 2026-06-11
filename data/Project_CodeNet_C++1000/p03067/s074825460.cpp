#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    string ans;
    if((b-c)*(c-a)>0){
        ans = "Yes";
    }else{
        ans = "No";
    }
    cout << ans << endl;
}