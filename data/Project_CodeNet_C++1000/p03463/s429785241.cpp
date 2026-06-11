#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n,a,b;
    cin >> n >> a >> b;
    for(int i = 0;;i++){
        if(i % 2 == 0){
            //Alice
            if(a+1 != b)a++;
            else if(1 < a)a--;
            else {
                cout << "Borys" << endl;
                break;
            }
        } else {
            //Borys
            if(b-1 != a)b--;
            else if(n > b)b++;
            else {
                cout << "Alice" << endl;
                break;
            }
        }
    }
}