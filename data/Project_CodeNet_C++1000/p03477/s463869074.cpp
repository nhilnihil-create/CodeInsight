#include<bits/stdc++.h>
using namespace std;

int main(){
    int la, lb, ra, rb;
    cin >> la >> lb >> ra >> rb;
    if(la + lb < ra + rb)cout << "Right" << endl;
    else if(la + lb == ra + rb)cout << "Balanced" << endl;
    else cout << "Left" << endl;
}