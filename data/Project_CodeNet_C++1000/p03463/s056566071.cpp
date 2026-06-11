#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    bool aturn = true;
    int turn = 0;
    while(true){
        turn++;
        if(aturn){
            if(a+1 != b)a++;
            else if(a != 1)a--;
            else break;

            aturn = false;
        }else{
            if(b-1 != a)b--;
            else if(b != n)b++;
            else break;

            aturn = true;
        }
        if(turn >= 1000000)break;
    }
    if(turn >= 1000000)cout << "Draw"<<endl;
    else if(aturn)cout<<"Borys"<<endl;
    else cout << "Alice"<<endl;
    
    
}
