#include <iostream>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n; int a; int b; cin >> n >> a >> b;
    bool terminar = false;
    int turno = 0;

    while(!terminar){
        if(turno % 2 == 0){
            if(a + 1 == b){
                if(a == 1)
                    terminar = true;
                else
                    --a;
            }
            else{
                ++a;
            }
        }
        else{
            if(b - 1 == a){
                if(b == n)
                    terminar = true;
                else
                    ++b;
            }
            else
                --b;
        }
        ++turno;
    }

    if(a > b){
        if(turno % 2 == 0)
            cout << "Borys\n";
        else
            cout << "Alice\n";
    }else{
        if(turno % 2 != 0)
            cout << "Borys\n";
        else
            cout << "Alice\n";
    }

    return 0;
}