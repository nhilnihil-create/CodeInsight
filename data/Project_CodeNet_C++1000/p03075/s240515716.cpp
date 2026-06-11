#include <iostream>

using namespace std;

int main(){
    int a, b, c, d, e, k;
    
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> k;
    
    if((e-a) > k){
        cout << ":(" <<endl;
    }else{
        if((d-a) > k){
            cout << ":(" <<endl;
        }else{
            if((c-a) > k){
                cout << ":(" <<endl;
            }else{
                if((b-a) > k){
                    cout << ":(" <<endl;
                }else{
                    cout << "Yay!" <<endl;
                }
            }
        }
    }


    return 0;
}