#include<bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int a, b, t, qtd = 0;
    cin >> a >> b >> t;

    for(int i = a; i <= (t+0.5); i+=a){
        qtd+=b;
    }

    cout << qtd << endl;
    
}