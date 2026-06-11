#include <iostream> 
#define ll long long
using namespace std;
int main(){
    ll a, b, c, k, zero=0;
    cin >> a >> b >> c >> k;
    if(a==b){
        cout << zero << endl;
    }
    else if(a-b>1e18||b-a>1e18){
        cout << "UNFAIR" << endl;
    }
    else{   
        if(k%2==0){
            cout << a-b << endl;
        }
        else{
            cout << b-a << endl;
        }
    }
}